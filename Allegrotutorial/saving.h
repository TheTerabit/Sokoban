void saving()//zapisuje stworzon¹ planszê do pliku
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *image = NULL;
	loading();
	ofstream custom_level("custom.txt");
	for (int i = 0; i < board_height; i++)
	{
		for (int j = 0; j < board_width; j++)
		{
			custom_level << build[i][j] << " ";
		}
		custom_level << "\n";
	}
	custom_level.close();
	editor = false;
	level = 1;
	load_level(level);
	draw();
}
