#include "Header.h"

int isFourOfAKind(int** hand) 
{
	return ((hand[0][1] == hand[1][1] && hand[0][1] == hand[2][1] && hand[0][1] == hand[3][1]) ||
		(hand[1][1] == hand[2][1] && hand[1][1] == hand[3][1] && hand[1][1] == hand[4][1]));
}

int isFullHouse(int** hand) 
{
	return ((hand[0][1] == hand[1][1] && hand[0][1] == hand[2][1] && hand[3][1] == hand[4][1]) ||
		(hand[0][1] == hand[1][1] && hand[2][1] == hand[3][1] && hand[3][1] == hand[4][1]));
}

int checkFlush(int** hand) 
{
	for (int i = 0; i < 3; i++) 
	{
		if (hand[i][0] != hand[i + 1][0])
		{
			return 0;
		}
	}
	return 1;
}

int checkStraight(int** hand) 
{
	for (int i = 0; i < 3; i++)
	{
		if (hand[i + 1][1] - hand[i][1] != 1)
		{
			return 0;
		}
	}
	return 1;
}

int isFlush(int** hand) 
{
	return (checkFlush(hand) && !(checkStraight(hand))) ? 1 : 0;
}

int isStraight(int** hand) 
{
	return (!checkFlush(hand) && (checkStraight(hand))) ? 1 : 0;
}

int isStraightFlush(int** hand) 
{
	return (checkFlush(hand) && (hand[4][1] - hand[0][1] == 4)) ? 1 : 0;
}

int isThreeOfAKind(int** hand) 
{
	if (isFourOfAKind(hand) || isFullHouse(hand)) 
	{
		return 0;
	}
	for (int i = 0; i < 3; i++) 
	{
		if (hand[i][1] == hand[i + 1][1] && hand[i + 1][1] == hand[i + 2][1]) 
		{
			return 1;
		}
	}
	return 0;
}

int isTwoPairs(int** hand) 
{
	if (isFourOfAKind(hand) || isFullHouse(hand)) 
	{
		return 0;
	}
	if ((hand[0][1] == hand[1][1] && hand[2][1] == hand[3][1]) || (hand[0][1] == hand[1][1] && hand[3][1] == 
		hand[4][1]) || (hand[1][1] == hand[2][1] && hand[3][1] == hand[4][1])) 
	{
		return 1;
	}
	return 0;
}

int isPair(int** hand) 
{
	if (isFourOfAKind(hand) || isFullHouse(hand) || isThreeOfAKind(hand) || isTwoPairs(hand))
	{
		return 0;
	}
	for (int i = 0; i < 4; i++)
	{
		if (hand[i][1] == hand[i + 1][1])
		{
			return 1;
		}
	}
	return 0;
}

int getHighestCard(int** hand) 
{ 
	return 4;
}

int getStatusOfHand(int** hand) 
{
	if (isStraightFlush(hand))
	{
		return 8;
	}
	if (isFourOfAKind(hand))
	{
		return 7;
	}
	if (isFullHouse(hand))
	{
		return 6;
	}
	if (isFlush(hand))
	{
		return 5;
	}
	if (isStraight(hand))
	{
		return 4;
	}
	if (isThreeOfAKind(hand))
	{
		return 3;
	}
	if (isTwoPairs(hand))
	{
		return 2;
	}
	if (isPair(hand))
	{
		return 1;
	}
	return 0;
}