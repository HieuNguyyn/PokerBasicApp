#include "Header.h"
#include<stdlib.h>
#include <stdio.h>
#include <conio.h>

const char suits[] = { 3,4,5,6 };
const char* faces[] = { "A", "2","3","4","5","6","7","8","9","10","J","Q","K" };

//-------------------------Screen-------------------------
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void textcolor(int x) {
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void input1(int& choice, int end) 
{
	cout << "----Input: ";
	cin >> choice;
	while (!cin || choice < 1 || choice > end) 
	{
		cin.clear();
		cin.ignore();
		textcolor(6);
		clrscr();
		cout << "INVALID INPUT" << endl <<
			"Please choose from 1 to " << end << " only: ";
		cin >> choice;
	}
	cout << endl;
}

void input2(int& choice, int end) 
{
	cin >> choice;
	while (!cin || choice < 1 || choice > end)
	{
		cin.clear();
		cin.ignore();
		textcolor(6);
		clrscr();
		cout << "INVALID INPUT" << endl <<
			"Please choose from 0 to 51 only: ";
		cin >> choice;
	}
	cout << endl;
}

void chooseDeck(int deck[SUITS][FACES]) 
{
	int choice;
	textcolor(6);
	gotoxy(40, 22);
	cout << "1. PRINT CURRENT DECK CARD" << endl;
	gotoxy(40, 23);
	cout << "2. SHUFFLE THE DECK" << endl;
	gotoxy(40, 24);
	cout << "3. BACK" << endl;
	gotoxy(40, 25);
	cout << "4. EXIT THE GAME" << endl;
	gotoxy(40, 26);
	input1(choice, 4);
	clrscr();
	if (choice == 1) 
	{
		printCardsShuffling(deck, suits, faces);
		chooseDeck(deck);
	}
	else if (choice == 2) 
	{
		shuffleCards(deck);
		textcolor(12);
		cout << "Shuffle Completed!" << endl << endl;
		chooseDeck(deck);
	}
	else if (choice == 3) 
	{
		mainmenu(deck);
	}
	else if (choice == 4)
	{
		return;
	}
}

void chooseSingleplayer(int deck[SUITS][FACES], int** hand) 
{
	int choice;
	textcolor(6);
	gotoxy(40, 13);
	cout << "1. DEAL FOR ONE HAND" << endl;
	gotoxy(40, 14);
	cout << "2. PRINT HAND" << endl;
	gotoxy(40, 15);
	cout << "3. CREATE HAND TEST" << endl;
	gotoxy(40, 16);
	cout << "4. GET STATUS OF HAND" << endl;
	gotoxy(40, 17);
	cout << "5. GET THE HIGHEST CARD" << endl;
	gotoxy(40, 18);
	cout << "6. BACK" << endl;
	gotoxy(40, 19);
	input1(choice, 6);
	clrscr();
	if (choice == 1) {
		clrscr();
		textcolor(12);
		hand = dealingForHand(deck);
		cout << "Hand dealt!" << endl;
		return chooseSingleplayer(deck, hand);
	}
	if (choice == 2) 
	{
		clrscr();
		printHand(hand, suits, faces);
		return chooseSingleplayer(deck, hand);
	}
	if (choice == 3) 
	{
		int a[5];
		for (int i = 0; i < 5; i++) 
		{
			textcolor(6);
			gotoxy(40, 21);
			cout << "----Input element a[" << i << "] : ";
			input2(a[i], 52);
		}
		hand = createHandTest(deck, a);
		return chooseSingleplayer(deck, hand);
	}
	if (choice == 4) 
	{
		clrscr();
		SortCards(hand);
		textcolor(6);
		cout << getStatusOfHand(hand) << " point(s). Congratulation!" << endl << endl;
		return chooseSingleplayer(deck, hand);
	}
	if (choice == 5) 
	{
		SortCards(hand);
		int highestCard = getHighestCard(hand);
		textcolor(6);
		cout << "Highest card is: " << endl << endl;
		printCard(faces[hand[highestCard][1]], suits[hand[highestCard][0]]);
		return chooseSingleplayer(deck, hand);
	}
	if (choice == 6) 
	{
		return mainmenu(deck);
	}
}

void chooseMultiplayer(int deck[SUITS][FACES], int*** hands, int n) 
{
	textcolor(12);
	int choice;
	textcolor(12);
	gotoxy(40, 14);
	cout << "1. DEAL FOR HANDS" << endl;
	textcolor(10);
	gotoxy(40, 15);
	cout << "2. RANKING HANDS" << endl;
	textcolor(9);
	gotoxy(40, 16);
	cout << "3. EVALUATE HANDS" << endl;
	textcolor(13);
	gotoxy(40, 17);
	cout << "4. DEALER" << endl;
	textcolor(11);
	gotoxy(40, 18);
	cout << "5. BACK" << endl;
	textcolor(14);
	gotoxy(40, 19);
	input1(choice, 5);
	clrscr();
	if (choice == 1) 
	{
		clrscr();
		hands = dealingForHands(deck, n, hands);
		textcolor(12);
		gotoxy(40, 20);
		cout << "Hands dealt!" << endl << endl;
		return chooseMultiplayer(deck, hands, n);
	}
	if (choice == 2) 
	{
		while (1) {
			clrscr();
			int* a = new int[n];
			a = rankingHands(hands, n);
			textcolor(10);
			gotoxy(40, 12);
			cout << "Rank of players: ";
			for (int i = 0; i < n; i++)
			{
				cout << a[i] + 1 << " ";
			}
			cout << endl;
			int choice;
			gotoxy(40, 17);
			textcolor(3);
			cout << "WOULD YOU LIKE TO PLAY AGAIN ?" << endl;
			gotoxy(40, 18);
			textcolor(12);
			cout << "1. PLAY AGAIN" << endl;
			gotoxy(40, 19);
			textcolor(12);
			cout << "2. BACK TO MAINMENU" << endl;
			gotoxy(40, 20);
			input1(choice, 2);
			if (choice == 1) {
				clrscr();
				int* a = new int[n];
				a = rankingHands(hands, n);
				textcolor(10);
				gotoxy(40, 12);
				cout << "Rank of players: ";
				for (int i = 0; i < n; i++)
				{
					cout << a[i] + 1 << " ";
				}
				cout << endl;
				return chooseMultiplayer(deck, hands, n);
			}
			else {
				return mainmenu(deck);
			}
		}
	}
	if (choice == 3) 
	{
		int s;
		textcolor(9);
		gotoxy(40, 13);
		cout << "Enter s rounds: ";
		cin >> s;
		evaluateHands(deck, hands, n, s);
		return chooseMultiplayer(deck, hands, n);
	}
	if (choice == 4) 
	{
		clrscr();
		Dealer(deck, hands, n);
		return chooseMultiplayer(deck, hands, n);
	}
	if (choice == 5) 
	{
		clrscr();
		return mainmenu(deck);
	}
}

void mainmenu(int deck[SUITS][FACES]) 
{
	textcolor(6);
	cout << "       ###########################################################################################   " << endl;
	cout << "     ##                                                                                           ##" << endl;
	cout << "     ##   # # #    ####   #    #  # # #   # # #       ####       #       ##         ##   # # #    ##" << endl;
	cout << "     ##   #    #  #    #  #   #   #       #    #     #          # #      # #       # #   #        ##" << endl;
	cout << "     ##   # # #   #    #  # ##    # # #   #    #     #         #   #     #  #     #  #   # # #    ##" << endl;
	cout << "     ##   #       #    #  #  #    #       # # #      # ###    # # # #    #   #   #   #   #        ##" << endl;
	cout << "     ##   #       #    #  #   #   #       #    #     #   #   #       #   #    # #    #   #        ##" << endl;
	cout << "     ##   #        ####   #    #  # # #   #     #     ###   #         #  #     #     #   # # #    ##" << endl;
	cout << "     ##                                                                                           ##" << endl;
	cout << "       ###########################################################################################  " << endl;
	cout << "                                     WELCOME TO OUR POKER GAME!!!!                              " << endl;
	cout << "                         PLEASE CHOOSE THE OPTION GIVEN BELOW TO START THE GAME                 ";
	int choice;
	textcolor(12);
	gotoxy(40, 14);
	cout << "1. DECK" << endl;
	textcolor(10); gotoxy(40, 15);
	cout << "2. SINGLEPLAYER" << endl;
	textcolor(9); gotoxy(40, 16);
	cout << "3. MULTIPLAYER" << endl;
	textcolor(3);
	gotoxy(40, 17);
	cout << "4. EXIT THE GAME " << endl;
	textcolor(11);
	gotoxy(40, 18);
	input1(choice, 4);
	if (choice == 1) 
	{
		clrscr();
		chooseDeck(deck);
	}
	if (choice == 2) 
	{
		clrscr();
		int** hand = new int* [5];
		for (int i = 0; i < 5; i++)
		{
			hand[i] = new int[2];
		}
		chooseSingleplayer(deck, hand);
	}
	if (choice == 3) 
	{
		clrscr();
		int n;
		textcolor(12);
		cout << "Enter n players (<=10): ";
		input1(n, 10);
		int*** hands = new int** [n];
		for (int i = 0; i < n; i++) 
		{
			hands[i] = new int* [5];
			for (int j = 0; j < 5; j++)
			{
				hands[i][j] = new int[2];
			}
		}
		chooseMultiplayer(deck, hands, n);
	}
	if (choice == 4)
	{
		clrscr();
		return;
	}
}