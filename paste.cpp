#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <Windows.h> //Sleep function

using namespace std;

const char dark = 0xB2;
int position = 15;

const int mapHeight = 30;
const int mapWidth = 30;

int enemyX;
int enemyY = 0;

//Creates map, player, and enemy
void map()
{
	system("cls");
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			if (y == enemyY && x == enemyX) {
				cout << "V";
			} 
			if (y == mapHeight - 1 && x == position) {
				cout << "#";
			}
			if (x == 0 || x == mapWidth - 1) {
				cout << dark;
			}
			else { cout << " "; }
		}
		cout << "\n";
	}
}



void enemies() {
	
	srand(time(0));
	enemyX = 1 + rand() % (mapWidth - 2);
	enemyY = 0;

}

//Players Movement

void plr() {

	while (true) {

		char key = _getch();

		map();
		enemies();
		if (key == 'a')
		{
			if (position == 1) {
				system("cls");
				cout << "Out Of Bounds...\n\nGame Over\n";
				break;

			}
			position--;

		}
		if (key == 'd')
		{
			if (position == 29) {
				system("cls");
				cout << "Out Of Bounds...\n\nGame Over\n";
				break;

			}

			position++;
		}
		if (key == 'q') { break; }


	}

}

//Calling the functions
int main() {

	plr();
}
