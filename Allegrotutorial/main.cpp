#include <stdio.h>
#include<fstream>
#include<iostream>
#include"base.h"
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_native_dialog.h"
using namespace std;
#include"show.h"
#include"loading.h"
#include"create_new.h"
#include"load_level.h"
#include"draw.h"
#include"saving.h"
#include"move.h"

int main(int argc, char **argv) {
	ALLEGRO_BITMAP  *image = NULL;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_DISPLAY_MODE   disp_data;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	bool redraw = true, doexit = false, close = false;
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
	return -1;
	}
	display = al_create_display(1000, 1000);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);

	load_level(level);
	draw();

	while (!doexit)////////////////////////////////////////////////////////////////////start gry
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
					move(1);
					m = 1;
					break;

				case ALLEGRO_KEY_DOWN:
					move(2);
					m = 2;
					break;

				case ALLEGRO_KEY_LEFT:
					move(3);
					m = 3;
					break;

				case ALLEGRO_KEY_RIGHT:
					move(4);
					m = 4;
					break;
						
				case ALLEGRO_KEY_ESCAPE:
					loading();
					lc = false;
					if ((level == 1)&&(editor==false))
						doexit = true;
					else
					{
						editor = false;
						level = 1;
						load_level(level);
						draw();
					}
					break;
						
				case ALLEGRO_KEY_R:
					if (editor == false)
					{
						loading();
						load_level(level);
						draw();
					}
					else
					{
						loading();
						editor = true;
						create_new_build();
						al_flip_display();
					}
					break;
				case ALLEGRO_KEY_N:
					if((editor==false)&&(level>2))
						score = goal;
					break;
				case ALLEGRO_KEY_ENTER:
					if((board[y][x+1]==6)&&(editor==false))
					{
						loading();
						level++;
						load_level(level);
						draw();
					}
					if ((board[y][x + 1] == 7) && (editor == false))
					{
						loading();
						editor = true;
						create_new_build();
						al_flip_display();
					}
					if ((board[y][x + 1] == 8) && (editor == false))
						ex = true;			
						
			}
		if(editor==true)//////////////////////////////////////////sterowanie w edytorze
			switch (ev.keyboard.keycode) {
				case ALLEGRO_KEY_1:
					cursor = 1;
					image = al_load_bitmap("wall.png");
					al_draw_bitmap(image, (x) * 50, (y) * 50, 0);
					al_flip_display();
					break;
				case ALLEGRO_KEY_6:
					cursor = 0;
					image = al_load_bitmap("empty.png");
					al_draw_bitmap(image, (x) * 50, (y) * 50, 0);
					al_flip_display();
					break;
				case ALLEGRO_KEY_2:
					cursor = 2;
					image = al_load_bitmap("box2.png");
					al_draw_bitmap(image, (x) * 50, (y) * 50, 0);
					al_flip_display();
					break;
				case ALLEGRO_KEY_3:
					cursor = 3;
					image = al_load_bitmap("done.png");
					al_draw_bitmap(image, (x) * 50, (y) * 50, 0);
					al_flip_display();
					break;
				case ALLEGRO_KEY_4:
					cursor = 4;
					image = al_load_bitmap("target.png");
					al_draw_bitmap(image, (x) * 50, (y) * 50, 0);
					al_flip_display();
					break;
				case ALLEGRO_KEY_5:
					cursor = 5;
					image = al_load_bitmap("robot.png");
					al_draw_bitmap(image, (x) * 50, (y) * 50, 0);
					al_flip_display();
					break;
				case ALLEGRO_KEY_SPACE:
					build[y][x] = cursor;
					if (cursor == 5)
					{
						if (robot_placed == true)
						{
							build[tmpy][tmpx] = 0;
							show(build[tmpy][tmpx], tmpx, tmpy);
							al_flip_display();
						}
						tmpx = x;
						tmpy = y;
						robot_placed = true;
					}
					break;
				case ALLEGRO_KEY_S:
					if(robot_placed==true)
						saving();
					break;
				}		
			}
			if (goal == score)/////////////////////////////////////////////////////////przejsæie poziomu
			{
				if (level == 12)
				{
					level = 1;
					image = al_load_bitmap("win.png");
					al_draw_bitmap(image, 250, 300, 0);
					al_flip_display();
					al_rest(1.0);
				}
				else {
					level++;
					image = al_load_bitmap("next_level.png");
					al_draw_bitmap(image, 250, 250, 0);
					al_flip_display();
					al_rest(1.0);	
				}
				lc = false;
				load_level(level);
				draw();
			}
			if ((ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)||(ex==true)) {
				close = true;
				break;
			}
		}
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_bitmap(image);
	return 0;
}
