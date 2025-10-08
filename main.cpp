#include <iostream> //love strings
#include <iomanip> //setw
#include <conio.h> //Get Keyboard inputs while continuing
#include <ctime> //srand and rand randomizers
#include <Windows.h> //Sleep function

using namespace std; //dont like using std::

const char dark = 0xB2; //UDC
int plrX = 15; //players position

//self explanitory
const int mapHeight = 30;
const int mapWidth = 30;

int enemyX;
int enemyY;

//Creates map, player, and enemy
void map()
{
	system("cls");
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			//if the enemyY and enemyX is where the y and x is, put down enemy (for values(x,y) go through every part of map)
			if (y == enemyY && x == enemyX) {
				cout << "V";
			}
			//if mapHeight(under the map) then place character there
			if (y == mapHeight - 1 && x == plrX) {
				cout << "#";
			}
			//Draws the border if x == 0 or mapWidth
			if (x == 0 || x == mapWidth - 1) { // "- 1" ?
				cout << dark;
			}
			//if none of the if statements, space
			else { cout << " "; }
		}
		cout << "\n";
	}
}


//randomizes enemies position on map
void enemies() {

	srand(time(0));
	enemyX = 1 + rand() % (mapWidth - 2);
	enemyY = 0; //puts enemy back at top of map

}

//Players Movement

void plr() {

	enemies();

	while (true) {

		if (_kbhit()) {
			char key = _getch();

			if (key == 'a')
			{
				if (plrX <= 1) {
					system("cls");
					cout << "Out Of Bounds...\n\nGame Over\n";
					break;

				}
				plrX--;


			}
			if (key == 'd')
			{
				if (plrX >= 29) {
					system("cls");
					cout << "Out Of Bounds...\n\nGame Over\n";
					break;

				}

				plrX++;
			}
			if (key == 'q') { break; }

		}
		map();

		//if enemy is at minimum map height, reset the enemy
		if (enemyY >= mapHeight) {
			enemies();
		}
		//if enemy x is same as plr and enemy y is under map height, game over
		if (enemyX == plrX && enemyY == mapHeight - 1)
		{ 
			system("cls");  
			cout << "Game Over..."; 
			break; 
		}
		
		else { enemyY++; } //makes enemy fall every milisecond (Sleep(100))


		Sleep(100); //1000 = 1 second | 100 = 1 milisecond

	}

}

//Calling the functions
int main() {

	plr();
}
