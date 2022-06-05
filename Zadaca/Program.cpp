#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"

using namespace std;

int main() 
{
	game_of_life the_game;

	bool n;
	do 
	{
		system("cls");

		the_game.iscrtaj();
		the_game.sljedeca_generacija();

		cout << "Nastavi (1/0): ";
		cin >> n;

	} while (n);

	return 0;
}