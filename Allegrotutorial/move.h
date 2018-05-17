void move(int d)/////////////////////////////////////////////poruszanie siê
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *image = NULL;
	int mx = 0, my = 0;//////////////////////////okreœlenie kierunku
	if (d == 1)
		my = -1;
	if (d == 2)
		my = 1;
	if (d == 3)
		mx = -1;
	if (d == 4)
		mx = 1;
	if (editor == false) {
		if (board[y + my][x + mx] == 0)//////////////////////////////zwyk³e poruszanie
		{
			image = al_load_bitmap("robot.png");
			al_draw_bitmap(image, (x + mx) * 50, (y + my) * 50, 0);
			if (board[y][x] != 4)
				board[y][x] = 0;
			image = al_load_bitmap("empty.png");
			if (board[y][x] == 4) {
				image = al_load_bitmap("target.png");
				board[y][x] = 4;
			}
			al_draw_bitmap(image, x * 50, y * 50, 0);
			board[y + my][x + mx] = 5;
			y = y + my;
			x = x + mx;
			al_flip_display();
		}
		else if (board[y + my][x + mx] > 5)/////////////////////////////opcje menu
		{
			if (board[y + my][x + mx] == 6)
			{
				loading();
				level++;
				load_level(level);
				draw();
			}
			if (board[y + my][x + mx] == 7)
			{
				loading();
				editor = true;
				create_new_build();
				al_flip_display();
			}
			if (board[y + my][x + mx] == 8)
			{
				loading();
				ex = true;
			}
			if ((board[y + my][x + mx] > 8) && (board[y + my][x + mx] != 100))
			{
				loading();
				level = board[y + my][x + mx] - 8;
				load_level(level);
				draw();
			}
			if (board[y + my][x + mx] == 100)
			{
				lc = true;
				loading();
				level = 12;
				load_level(1);
				draw();
			}
		}

		else if ((board[y + my][x + mx] == 2) || (board[y + my][x + mx] == 3))/////////////////przesuwanie pude³ek
		{
			if (board[y + my*(2)][x + mx*(2)] == 0) {
				image = al_load_bitmap("robot.png");
				al_draw_bitmap(image, (x + mx) * 50, (y + my) * 50, 0);
				image = al_load_bitmap("empty.png");
				if (board[y][x] == 4)
					image = al_load_bitmap("target.png");
				al_draw_bitmap(image, x * 50, y * 50, 0);
				image = al_load_bitmap("box2.png");
				al_draw_bitmap(image, (x + mx * 2) * 50, (y + my * 2) * 50, 0);
				board[y + my * 2][x + mx * 2] = 2;
				if (board[y + my][x + mx] == 3)
					board[y + my][x + mx] = 4;
				else
					board[y + my][x + mx] = 5;
				if (board[y][x] != 4)
					board[y][x] = 0;
				y = y + my;
				x = x + mx;
				al_flip_display();
			}
			else if (board[y + my * 2][x + mx * 2] == 4) {
				image = al_load_bitmap("robot.png");
				al_draw_bitmap(image, (x + mx) * 50, (y + my) * 50, 0);
				image = al_load_bitmap("empty.png");
				if (board[y][x] == 4)
					image = al_load_bitmap("target.png");
				al_draw_bitmap(image, x * 50, y * 50, 0);
				image = al_load_bitmap("done.png");
				al_draw_bitmap(image, (x + 2 * mx) * 50, (y + my * 2) * 50, 0);
				board[y + my * 2][x + mx * 2] = 3;
				if (board[y + my][x + mx] == 3)
					board[y + my][x + mx] = 4;
				else
					board[y + my][x + mx] = 5;
				if (board[y][x] != 4)
					board[y][x] = 0;
				y = y + my;
				x = x + mx;
				al_flip_display();
			}
		}
		else if ((board[y + my][x + mx] == 4))////////////////////////////////////////////wchodzenie na gwiazdki
		{
			image = al_load_bitmap("robot.png");
			al_draw_bitmap(image, (x + mx) * 50, (y + my) * 50, 0);
			image = al_load_bitmap("empty.png");
			if (board[y][x] == 4)
				image = al_load_bitmap("target.png");
			al_draw_bitmap(image, x * 50, y * 50, 0);
			if (board[y][x] != 4)
				board[y][x] = 0;
			y = y + my;
			x = x + mx;
			al_flip_display();
		}
		score = 0;//////////////////////////////////////////////////////////////////////sprawdzanie wyniku
		for (int i = 0; i < board_height; i++)
		{
			for (int j = 0; j < board_width; j++)
			{
				if (board[i][j] == 3)
					score++;
			}
		}
	}
	else////////////////////////////////////////////////tryb edytora
	{
		if ((x + mx != 0) && (x + mx != 19) && (y + my != 19) && (y + my != 0))
		{
			if (cursor == 0)
				image = al_load_bitmap("empty.png");
			if (cursor == 1)
				image = al_load_bitmap("wall.png");
			if (cursor == 2)
				image = al_load_bitmap("box2.png");
			if (cursor == 3)
				image = al_load_bitmap("done.png");
			if (cursor == 4)
				image = al_load_bitmap("target.png");
			if (cursor == 5)
				image = al_load_bitmap("robot.png");
			al_draw_bitmap(image, (x + mx) * 50, (y + my) * 50, 0);
			show(build[y][x], x, y);
			y = y + my;
			x = x + mx;
			al_flip_display();
		}
	}
}
