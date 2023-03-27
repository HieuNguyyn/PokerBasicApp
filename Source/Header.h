#ifndef _console_header
#define _console_header


#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7


#define key_Up		1072
#define key_Down	1080
#define key_Left	1075
#define key_Right	1077
#define key_none	-1

//--------------------------------------------------------

#include <windows.h>

//--------------------------------------------------------

int inputKey();

//-------------------------Screen-------------------------
void clrscr();

//screen: goto [x,y]
void gotoXY(int column, int line);

//screen: get [x]
int whereX();

//screen: get [y]
int whereY();

void TextColor(int color);
//end----------------------Screen----------------------end


#endif
#include <iostream>
#include <algorithm>
#include <ctime>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

// basic console functions, collected by Nguyen Trung Thanh
// abcxyz tcIT
using namespace std;

const int SUITS = 4, FACES = 13;

//menu
void input1(int& choice, int end);
void mainmenu(int deck[SUITS][FACES]);

//deck_hand.cpp
void SortCards(int** a);
void shuffleCards(int deck[SUITS][FACES]);											//1.1
void printCardsShuffling(int deck[SUITS][FACES], const char suits[], const char* faces[]);		//1.2
void printHand(int** hand, const char suits[], const char* faces[]);							//2.1.b
int** createHandTest(int deck[SUITS][FACES], int a[]);								//2.1.c
int** dealingForHand(int deck[SUITS][FACES]);										//2.1.a
int*** dealingForHands(int deck[SUITS][FACES], int n, int*** hands);				    //2.2.a
int* rankingHands(int*** hands, int n);												//2.2.c
int* evaluateHands(int deck[SUITS][FACES], int*** hands, int n, int s);				//2.2.d
void Dealer(int deck[SUITS][FACES], int*** hands, int n);							//2.3

//status.cpp
int isStraightFlush(int** hand);													//2.1.h
int isFourOfAKind(int** hand);														//2.1.d
int isFullHouse(int** hand);														//2.1.e
int isFlush(int** hand);															//2.1.f
int isStraight(int** hand);															//2.1.g
int isThreeOfAKind(int** hand);														//2.1.i
int isTwoPairs(int** hand);															//2.1.j
int isPair(int** hand);																//2.1.k
int getHighestCard(int** hand);														//2.1.l
int getStatusOfHand(int** hand);													//2.2.b
void printCards(int** cards, int numOfCards);
void printCard(const char* f, char s);
void textcolor(int x);
void gotoxy(int x, int y);
