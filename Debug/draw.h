void draw()//rysuje ca³¹ planszê
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *image = NULL;
	for (int i = 0; i < board_height; i++)
	{
		for (int j = 0; j < board_width; j++)
		{
			show(board[i][j], j, i);
		}
	}
	if (level == 1)
	{
		image = al_load_bitmap("play.png");
		al_draw_bitmap(image, 500, 550, 0);
		image = al_load_bitmap("editor.png");
		al_draw_bitmap(image, 500, 650, 0);
		image = al_load_bitmap("exit.png");
		al_draw_bitmap(image, 500, 750, 0);
		image = al_load_bitmap("sokoban1.png");
		al_draw_bitmap(image, 200, 200, 0);
	}
	image = al_load_bitmap("controls.png");
	al_draw_bitmap(image, 50, 0, 0);
	al_flip_display();
}
