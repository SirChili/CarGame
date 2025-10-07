#include <iostream>
#include <iomanip>

using namespace std;

const char dark = 0xB2;

void map()
{

	cout << "\n";

	for (int i = 0; i < 30; i++)
	{
		cout << " " << setw(5);
		cout << dark << setw(40);
		cout << dark << "\n";
	}

	

}


int main() {

	map();
}
