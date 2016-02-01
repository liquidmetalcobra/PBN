#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "bouncer.hpp"
#include "collider.hpp"
#include "globals.h"
#include "tile.hpp"
#include "ballGenerator.hpp"
#include <vector>
#include "animator.hpp"
#include <allegro5/allegro_native_dialog.h>
#include "Factory.hpp"

enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
int main(int argc, char **argv) {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	bool redraw = true;
	bool doexit = false;
	bool key[4] = { false, false, false, false };

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}
	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	collider collide;
	std::vector<bouncer *> balls;
	std::vector<tile*> tiles;
	std::vector<move *> moveVector;
	ALLEGRO_BITMAP *image = NULL;
	image = al_load_bitmap("megamanss.png");
	
	if (!image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, NULL);
		al_destroy_display(display);
		return 0;
	}
	
	for (int i = 0; i < NUM_BALLS; i++)
	{
		bouncer* a;
		a = new bouncer(30 * i, 30 * i, 10, i / 5.0, i);

		balls.push_back(a);
		//  collide.add(a);
	}
	for (int i = 0; i < NUM_TILES; i++)
	{
		tile * a;
		//     std::cout << i%16 << "\t" << i/12 << "\n";
		a = new tile(TILE_SIZE * (i % 16), TILE_SIZE * (i / 16), TILE_SIZE);
		tiles.push_back(a);
		//  collide.add(a);
	}
	animator *anim = new animator("megamanss.png", "Source/megamanss.txt");
	//ballGenerator *bg = new ballGenerator(100,100,&collide,&balls);
	//PokemonFactory pf;

	pokemon * p = new pokemon("treeko", 1, 2, 3, 4);
	MoveFactory *mf = new MoveFactory();
	move *m = mf->Create(SWAG, "swag", p, p, 0, 400, 200);
	moveVector.push_back(m);
	collide.add(p);
	collide.add(m);
	//    bouncer b(20,20,32,3,4);
	//   bouncer c(30,30,32,4,4);
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}
	

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");

		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);



	std::cout << "\nDONE WITH INIT\n";
	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			collide.update();
			anim->update();
			for (int i = 0; i < moveVector.size(); i++)
			{
				std::cout << "moveVector.size()" << moveVector.size() << "\n";
				if (moveVector[i]->markForDeath == true)
				{

					delete moveVector[i];
					moveVector.erase(moveVector.begin() + i);
					i--;

				}
				else
				{
					moveVector[i]->update();
				}
			}
			/*
			if (m != NULL && m->markForDeath == true)
			{
			std::cout << "deleting object";
			delete m;
			m = NULL;
			}
			else if (m!= NULL)

			m->update();
			*/
			for (int i = 0; i < balls.size(); i++)
			{
				if (balls[i]->markForDeath == true)
				{
					collide.remove(balls[i]);
					delete balls[i];
					balls.erase(balls.begin() + i);
					i--;
				}
				else
				{
					balls[i]->update();
				}

			}
			
			if (key[KEY_UP]) {
				anim->switchAnimations(1);
			}

			if (key[KEY_DOWN]) {
				anim->switchAnimations(2);
			}

			if (key[KEY_LEFT]) {
				anim->switchAnimations(3);
			}

			if (key[KEY_RIGHT]) {
				anim->switchAnimations(4);
			}
			
			// for (int i = 0; i < tiles.size(); i++)
			//   tiles[i]->update();

			p->update();
			//bg->update();
			redraw = true;
		}



		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_set_target_bitmap(al_get_backbuffer(display));
			al_clear_to_color(al_map_rgb(0, 0, 0));
			// al_draw_bitmap(image,200,200,0);

			for (int i = 0; i < moveVector.size(); i++)
				moveVector[i]->draw();
			/*
			for (int i = 0; i < tiles.size(); i++)
			tiles[i]->draw();
			for (int i = 0; i < balls.size(); i++)
			balls[i]->draw();*/
			anim->draw(100, 100);
			p->draw();

			
		
			al_flip_display();
		}
	}
	for (int i = 0; i < tiles.size(); i++)
		delete tiles[i];
	for (int i = 0; i < balls.size(); i++)
		delete balls[i];


	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}