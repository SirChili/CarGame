#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <Windows.h> //Sleep function

using namespace std;

const char dark = 0xB2;
int position = 15;

//Map Creation
void map()
{
	for (int i = 0; i < 30; i++) {
		cout << dark << setw(30) << dark << "\n";
	}
}

void enemies() {
	//This is randomized but plays as the player, change it to play as enemies instead
	while (true) {

		char key = _getch();

		if (key == 'q') {
			break;
		}

		srand(time(0));
		int random = rand() % 30;
		Sleep(700);
		system("cls");
		map();

		cout << setw(random) << "#";

	}
	
}

//Players Movement
void plr() {

	cout << setw(position) << "#";
	
	while(true){
		
		char key = _getch();
		
		if (key == 'a')
		{ 
			if (position == 1) {
				system("cls");
				cout << "Out Of Bounds...\n\nGame Over\n";
				break;
			}

			system("cls");
			map();
			position--;
		
			cout << setw(position) << "#";
		}
		if (key == 'd')
		{ 
			if (position == 31) {
				system("cls");
				cout << "Out Of Bounds...\n\nGame Over\n";
				break;

			}
			system("cls");
			map();
			position++; 

			cout << setw(position) << "#";
		}
		if (key == 'q'){break;}
			
		
	}

}

//Calling the functions
int main() {

	map();
	plr();
}

