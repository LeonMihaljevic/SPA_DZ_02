#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPAC = 40;
	static const unsigned int REDAK = 20;
	bool _generacija[REDAK][STUPAC];
	bool _sljedeca_generacija[REDAK][STUPAC];
	bool slucajna_vrijednost();
	bool celija_zauzeta(int i, int j);

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif