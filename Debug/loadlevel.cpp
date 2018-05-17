#include"loadlevel.h"
#include<fstream>

void load_level(int v)//wczytuje odpowiedni poziom z pliku do tablicy board
{
	ifstream in("save.txt");
	ifstream load_custom("custom.txt");
	for (int s = 1; s <= v; s++)
	{
		score = 0;
		goal = 0;
		for (int i = 0; i < board_height; i++)
		{
			for (int j = 0; j < board_width; j++)
			{
				if (lc == true)
					load_custom >> board[i][j];
				else
					in >> board[i][j];
				if (board[i][j] == 5) {
					x = j;
					y = i;
				}
				if (board[i][j] == 4) {
					goal = goal + 1;
				}
				if (board[i][j] == 3) {
					goal++;
					score++;
				}
			}
		}
	}
}
