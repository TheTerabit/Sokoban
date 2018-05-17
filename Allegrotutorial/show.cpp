#include"show.h"

void show(int p, int xp, int yp)//odœwie¿a odpowiednie pole na planszy
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *image = NULL;
	if (p == 0)
		image = al_load_bitmap("empty.png");
	if (p == 1)
		image = al_load_bitmap("wall.png");
	if (p == 2)
		image = al_load_bitmap("box.png");
	if (p == 3)
		image = al_load_bitmap("done.png");
	if (p == 4)
		image = al_load_bitmap("target.png");
	if (p == 5)
		image = al_load_bitmap("robot.png");
	if ((p > 5) && (p <= 20))
		image = al_load_bitmap("door.png");
	if (p == 21)
		image = al_load_bitmap("1.png");
	if (p == 22)
		image = al_load_bitmap("2.png");
	if (p == 23)
		image = al_load_bitmap("3.png");
	if (p == 24)
		image = al_load_bitmap("4.png");
	if (p == 25)
		image = al_load_bitmap("5.png");
	if (p == 26)
		image = al_load_bitmap("6.png");
	if (p == 27)
		image = al_load_bitmap("7.png");
	if (p == 28)
		image = al_load_bitmap("8.png");
	if (p == 29)
		image = al_load_bitmap("9.png");
	if (p == 30)
		image = al_load_bitmap("10.png");
	if (p == 100)
		image = al_load_bitmap("door.png");
	if (p == 1000)
		image = al_load_bitmap("custom.png");
	if (!image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return;
	}
	al_draw_bitmap(image, xp * 50, yp * 50, 0);
}
