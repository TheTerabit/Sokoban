void create_new_build()//tworzy now¹ planszê gotow¹ do edytowania
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *image = NULL;
	cursor = 0;
	robot_placed = false;
	for (int i = 0; i < board_height; i++)
	{
		for (int j = 0; j < board_width; j++)
		{
			build[i][j] = 1;
			build[0][0] = 1000;
			show(build[i][j], j, i);
		}
	}
	x = 1;
	y = 1;
	image = al_load_bitmap("empty.png");
	al_draw_bitmap(image, x * 50, y * 50, 0);
	image = al_load_bitmap("controls_editor.png");
	al_draw_bitmap(image, 50, 0, 0);
}