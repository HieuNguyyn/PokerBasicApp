#include "Header.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

int main() {
	SetConsoleOutputCP(437);
	SetConsoleCP(437);
	srand(time(NULL));
	int deck[SUITS][FACES];
	for (int i = 0; i < 52; i++)
	{
		deck[0][i] = i; //gan gia tri ban dau cho tung o tu 0 den 51
	}
	shuffleCards(deck);
    mainmenu(deck);
}
