#include <iostream>
#include <conio.h>
#define DEBUG 0
using namespace std;

bool validate(char map[7][7])
{
	if ((map[1][1] == 'O' || map[1][1] == 'X') && map[3][1] == map[1][1] && map[5][1] == map[1][1]) { cout << "The winner is player " << map[1][1] << "!\n"; return true; } //Left Vertical
	else if ((map[1][3] == 'O' || map[1][3] == 'X') && map[3][3] == map[1][3] && map[5][3] == map[1][3]) { cout << "The winner is player " << map[1][3] << "!\n"; return true; } //Middle Vertical
	else if ((map[1][5] == 'O' || map[1][5] == 'X') && map[3][5] == map[1][5] && map[5][5] == map[1][5]) { cout << "The winner is player " << map[1][5] << "!\n"; return true; } //Right Vertical

	else if ((map[1][1] == 'O' || map[1][1] == 'X') && map[1][3] == map[1][1] && map[1][5] == map[1][1]) { cout << "The winner is player " << map[1][1] << "!\n"; return true; } //Top Horizontal
	else if ((map[3][1] == 'O' || map[3][1] == 'X') && map[1][3] == map[3][1] && map[1][5] == map[3][1]) { cout << "The winner is player " << map[3][1] << "!\n"; return true; } //Middle Horizontal
	else if ((map[5][1] == 'O' || map[5][1] == 'X') && map[5][3] == map[5][1] && map[5][5] == map[5][1]) { cout << "The winner is player " << map[5][1] << "!\n"; return true; } //Bottom Horizontal

	else if ((map[1][1] == 'O' || map[1][1] == 'X') && map[3][3] == map[1][1] && map[5][5] == map[1][1]) { cout << "The winner is player " << map[1][1] << "!\n"; return true; } //Left to right Diagonal
	else if ((map[1][5] == 'O' || map[1][5] == 'X') && map[3][3] == map[1][5] && map[5][1] == map[1][5]) { cout << "The winner is player " << map[1][5] << "!\n"; return true; } //Right to left Diagonal

	else if (map[1][1] != ' ' && map[1][3] != ' ' && map[1][5] != ' ' && map[3][1] != ' ' && map[3][3] != ' ' && map[3][5] != ' ' && map[5][1] != ' ' && map[5][3] != ' ' && map[5][5] != ' ') { cout << "No one won! :(\n"; return true; } //Draw
	return false;
}

int main()
{
	char linia[7][7] = 
	{
		{'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#'},
		{'#' ,' ' ,'#' ,' ' ,'#' ,' ' ,'#'},
		{'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#'},
		{'#' ,' ' ,'#' ,' ' ,'#' ,' ' ,'#'},
		{'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#'},
		{'#' ,' ' ,'#' ,' ' ,'#' ,' ' ,'#'},
		{'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#'},
	};
	int input = 0;
	char turn = 'X';
	bool finish = false;
	int posY = 0, posX = 0;
	while (!finish)
	{
		while (input != 32)
		{
			if (DEBUG)
			{
				cout << "Position X: " << posX << endl;
				cout << "Position Y: " << posY << endl;
			}
			cout << "Its " << turn << "'s turn!\n";
			for (int y = 0; y < 7; y++) 
			{ 
				for (int x = 0; x < 7; x++)
				{
					if (linia[y][x] == '#' && y == posY && x == posX) { cout << "\x1B[30;43m#\x1B[m"; }
					else if (linia[y][x] == ' ' && y == posY && x == posX) { cout << "\x1B[30;42m \x1B[m"; }
					else if ((linia[y][x] == 'X' || linia[y][x] == 'O') && y == posY && x == posX) { cout << "\x1B[30;41m"<< linia[y][x] <<"\x1B[m"; }
					else { cout << linia[y][x]; }
				}
				cout << endl;
			}
			input = _getch();
			if (input == 68 || input == 100)//RIGHT
			{
				posX++;
				if (posX > 6) posX = 6;
			}
			else if (input == 65 || input == 97)//LEFT
			{
				posX--;
				if (posX < 0) posX = 0;
			}
			else if (input == 119 || input == 87)//UP
			{
				posY--;
				if (posY < 0) posY = 0;

			}
			else if (input == 83 || input == 115)//DOWN
			{
				posY++;
				if (posY > 6) posY = 6;
			}
			system("cls");
		}
		if (linia[posY][posX] == ' ')
		{
			linia[posY][posX] = turn;
			switch (turn)
			{
			case 'X':
				turn = 'O';
				break;
			case 'O':
				turn = 'X';
				break;
			}
		}
		input = 0;
		finish = validate(linia);
		if (finish)
		{
			for (int y = 0; y < 7; y++)
			{
				for (int x = 0; x < 7; x++)
				{
					cout << linia[y][x];
				}
				cout << endl;
			}
			system("pause");
		}
	}
}