void loading()
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *image = NULL;
	image = al_load_bitmap("loading2.png");
	al_draw_bitmap(image, 250, 250, 0);
	al_flip_display();
}