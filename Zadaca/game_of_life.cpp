#include "game_of_life.h"
#include <ctime>

game_of_life::game_of_life()
{
	srand(time(nullptr));

	for (int i = 0; i < REDAK; i++)
	{
		for (int j = 0; j < STUPAC; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

bool game_of_life::slucajna_vrijednost()
{
	return rand() % 4 == 0;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (_generacija[i][j] == true)
	{
		return true;
	}

	else
	{
		return false;
	}
}


void game_of_life::sljedeca_generacija()
{
	int susjed = 0;
	for (int i = 0; i < REDAK; i++)
	{
		for (int j = 0; j < STUPAC; j++)
		{
			susjed = _generacija[i - 1][j - 1]
				+ _generacija[i + 1][j + 1]
				+ _generacija[i - 1][j + 1]
				+ _generacija[i + 1][j - 1]
				+ _generacija[i - 1][j]
				+ _generacija[i + 1][j]
				+ _generacija[j + 1][i]
				+ _generacija[j - 1][i];

			if (susjed == 2)
			{
				_sljedeca_generacija[i][j] = _generacija[i][j];
			}
			else if (susjed == 3)
			{
				_sljedeca_generacija[i][j] = true;
			}
			else if (susjed < 2)
			{
				_sljedeca_generacija[i][j] = false;
			}
			else if (susjed > 3)
			{
				_sljedeca_generacija[i][j] = false;
			}
		}
	}

	for (int i = 0; i < REDAK; i++)
	{
		for (int j = 0; j < STUPAC; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAK; i++)
	{
		for (int j = 0; j < STUPAC; j++)
		{
			if (_generacija[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}
}