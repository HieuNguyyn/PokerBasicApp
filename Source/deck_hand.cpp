#include "Header.h"

// hiển thị n lá bài
void printCards(int** cards, int numOfCards)
{
	const char suits[] = { 3, 4, 5, 6 };
	const char* faces[] = { "A", "2","3","4","5","6","7","8","9","10","J","Q","K" };
	const int r = 5; // chiều cao của lá bài hay số dòng in ra
	const int w = 7; // chiều ngang của lá bài
	const int c = w * numOfCards + (numOfCards - 1); // số cột cần in ra dựa vào chiều ngang của lá bài

	// 201 205 205 205 205 205 187
	// 186 A♥                  186
	// 186                     186
	// 186                     186
	// 200 205 205 205 205 205 188

	//╔═════╗
	//║A♥   ║
	//║     ║
	//║     ║
	//╚═════╝

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (i == 0) // hàng đầu tiên
			{
				if (j % (w + 1) == 0) // góc trái trên của mỗi lá bài
				{
					cout << char(201); // ╔
				}
				else if (j % (w + 1) == w - 1) // góc phải trên của mỗi lá bài
				{
					cout << char(187); // ╗
				}
				else if (j % (w + 1) == w) // khoảng cách giữa các lá bài
				{
					cout << " ";
				}
				else // cạnh trên của mỗi lá bài
				{
					cout << char(205); // ═
				}
			}
			else if (i == r - 1) // hàng cuối cùng
			{
				if (j % (w + 1) == 0)  // góc trái dưới của mỗi lá bài
				{
					cout << char(200); // ╚
				}
				else if (j % (w + 1) == w - 1) // góc phải dưới của mỗi lá bài
				{
					cout << char(188); // ╝
				}
				else if (j % (w + 1) == w) // khoảng cách giữa các lá bài
				{
					cout << " ";
				}
				else // cạnh trên của mỗi lá bài
				{
					cout << char(205); // ═
				}
			}
			else // các hàng còn lại
			{
				if (j % (w + 1) == 0) // cạnh trái của mỗi lá bài
				{
					cout << char(186); // ║
				}
				else if (j % (w + 1) == w - 1) // cạnh phải của mỗi lá bài
				{
					if (i == 1 && cards[j / (w + 1)][1] == 9) // trường hợp lá số 10 cần xoá 1 khoảng cách
					{
						cout << "\b"; // xoá 1 khoảng cách
					}
					cout << char(186); // ║
				}
				else if (i == 1 && j % (w + 1) == 1) // hiển thị số của mỗi lá bài
				{
					cout << faces[cards[j / (w + 1)][1]]; // A 2 3 4 ... Q K
				}
				else if (i == 1 && j % (w + 1) == 2) // Hiển thị chất của mỗi lá bài
				{
					cout << suits[cards[j / (w + 1)][0]];
				}
				else // khoảng trống giữa lá bài và các lá bài
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}
}

void printCard(const char* f, char s) 
{
	const int r = 5; // chiều cao của lá bài hay số dòng in ra
	const int w = 7; // chiều ngang của lá bài
	
	// 201 205 205 205 205 205 187
	// 186 A♥                  186
	// 186                     186
	// 186                     186
	// 200 205 205 205 205 205 188

	//╔═════╗
	//║A♥   ║
	//║     ║
	//║     ║
	//╚═════╝

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					cout << char(201);
				}
				else if (j == w - 1)
				{
					cout << char(187);
				}
				else
				{
					cout << char(205);
				}
			}
			else if (i == 1)
			{
				if (j == 0)
				{
					cout << char(186);
				}
				else if (j == 1)
				{
					cout << f;
				}
				else if (j == 2)
				{
					cout << s;
				}
				else if (j == w - 1)
				{
					if (strcmp(f, "10") == 0)
					{
						cout << '\b' << char(186);
					}
					else
					{
						cout << char(186);
					}
				}
				else
				{
					cout << " ";
				}
			}
			else if (i == r - 1)
			{
				if (j == 0)
				{
					cout << char(200);
				}
				else if (j == w - 1)
				{
					cout << char(188);
				}
				else
				{
					cout << char(205);
				}
			}
			else
			{
				if (j == 0 || j == w - 1)
				{
					cout << char(186);
				}
				else
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}
}

void SortCards(int** a) 
{
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			if (a[i][1] > a[j][1])
			{
				int temp_suit = a[j][0];
				int temp_face = a[j][1];
				a[j][0] = a[i][0];
				a[j][1] = a[i][1];
				a[i][0] = temp_suit;
				a[i][1] = temp_face;
			}
}

void shuffleCards(int deck[SUITS][FACES]) 
{							
	int* b = new int[52];
	for (int i = 0; i < SUITS; i++)
	{
		for (int j = 0; j < FACES; j++)
		{
			b[i * FACES + j] = deck[i][j];
		}
	}
	random_shuffle(b, b + 52);
	for (int i = 0; i < 52; i++)
	{
		deck[0][i] = b[i];
	}
	delete[]b;
}

void printCardsShuffling(int deck[SUITS][FACES], const char suits[], const char* faces[]) 
{	
	int count = 0;
	int** cards = new int* [FACES];
	for (int i = 0; i < FACES; ++i)
	{
		cards[i] = new int[2];
	}
	while (count != 52)
	{
		for (int row = 0; row < SUITS; row++)
		{
			for (int col = 0; col < FACES; col++)
			{
				if (deck[row][col] == count) 
				{
					cards[count % FACES][0] = row;
					cards[count % FACES][1] = col;
					row = -1;
					count++;
					if (count % FACES == 0)
					{
						printCards(cards, FACES);
					}
					break;
				}
			}
		}
	}
	for (int i = 0; i < FACES; ++i)
	{
		delete[] cards[i];
	}
	delete[] cards;
	cout << endl;
}

void printHand(int** hand, const char suits[], const char* faces[]) 
{
	printCards(hand, 5);
}

int** createHandTest(int deck[SUITS][FACES], int a[]) 
{						
	int** hand = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		hand[i] = new int[2];
	}
	int card_ord = 0;
	while (card_ord < 5)
	{
		for (int row = 0; row < SUITS; row++)
		{
			for (int col = 0; col < FACES; col++)
			{
				if (deck[row][col] == a[card_ord]) 
				{
					hand[card_ord][0] = row;
					hand[card_ord][1] = col;
					row = -1;
					card_ord++;
					break;
				}
			}
		}
	}
	cout << "Created!" << endl << endl;
	return hand;
}

int** dealingForHand(int deck[SUITS][FACES]) 
{			
	int** hand = new int* [5];
	for (int i = 0; i < 5; i++) 
	{
		hand[i] = new int[2];
	}
	int card_ord = 0;
	for (int row = 0; row < SUITS && card_ord < 5; row++) 
	{
		for (int col = 0; col < FACES; col++)
		{
			if (deck[row][col] == card_ord) 
			{
				hand[card_ord][0] = row;
				hand[card_ord][1] = col;
				row = -1;
				card_ord++;
				break;
			}
		}
	}
	return hand;
}

int*** dealingForHands(int deck[SUITS][FACES], int n, int*** hands) 
{			
	int card_ord = 0;
	int card_ord_person = 0;
	shuffleCards(deck);
	for (int row = 0; row < SUITS && card_ord_person < 5; row++)	
	{
		for (int col = 0; col < FACES; col++)
		{
			if (deck[row][col] == card_ord) 
			{
				hands[card_ord % n][card_ord_person][0] = row;		
				hands[card_ord % n][card_ord_person][1] = col;
				row = -1;
				card_ord++;
				if (card_ord % n == 0)
				{
					card_ord_person++;
				}
				break;
			}
		}
	}
	return hands;
}

int* rankingHands(int*** hands, int n) 
{
	int* result = new int[n];
	int* ranking = new int[n];
	int** hand = new int* [5];
	for (int i = 0; i < 5; i++) {
		hand[i] = new int[2];
	}
	for (int i = 0; i < n; i++) 
	{
		ranking[i] = i;
		for (int j = 0; j < 5; j++) 
		{
			hand[j][0] = hands[i][j][0];
			hand[j][1] = hands[i][j][1];
		}
		result[i] = getStatusOfHand(hand);
	}
	gotoxy(40, 13);
	int max = result[0];
	int maxplace = 0;
	for (int i = 1; i < n; i++)
	{
		if (result[i] > max)
		{
			max = result[i];
			maxplace = i;
		}
	}
	cout << "Congratulate Player #" << maxplace + 1 << " !" << endl << endl;
	return result;
}


int* evaluateHands(int deck[SUITS][FACES], int*** hands, int n, int s) 
{
	int round = 0;
	int* result = new int[n];
	for (int i = 0; i < n; i++)
	{
		result[i] = 0;
	}
	int** hand = new int* [5];
	for (int i = 0; i < 5; i++) 
	{
		hand[i] = new int[2];
	}
	do 
	{
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < 5; j++) 
			{
				hand[j][0] = hands[i][j][0];
				hand[j][1] = hands[i][j][1];
			}
			SortCards(hand);
			result[i] += getStatusOfHand(hand);
		}
		for (int i = 0; i < n; i++)
		{
			cout << result[i] << " ";
		}
		cout << endl;
		shuffleCards(deck);
		dealingForHands(deck, n, hands);
		round++;
	} 
	while (round != s);
	//CONGRATULATE WINNER
	int max = result[0];
	int maxplace = 0;
	for (int i = 1; i < n; i++)
	{
		if (result[i] > max) 
		{
			max = result[i];
			maxplace = i;
		}
	}
	cout << "Congratulate Player #" << maxplace + 1 << " !" << endl << endl;
	return result;
}


void PickUpCardBetter(int deck[SUITS][FACES], int*** hands, int n, const char suits[], const char* faces[]) 
{
	int Po_left = n * 4;
	int tang = 0;
	int dem = 0;
	int dem1 = 0, dem2 = 0;
	int rowT, colT;
	int tempS, tempR;
	for (int i = 0; i < 5; i++) 
	{
		tempS = hands[0][i][0];
		tempR = hands[0][i][1];
		printCard(faces[tempR], suits[tempS]);
	}
	cout << " ";
	int** hand = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		hand[i] = new int[2];
	}
	int** se = new int* [3];
	for (int i = 0; i < 3; i++) 
	{
		se[i] = new int[2];
	}
	for (int j = 0; j < 5; j++) 
	{
		hand[j][0] = hands[0][j][0];
		hand[j][1] = hands[0][j][1];
	}
	int a = getStatusOfHand(hand);
	cout << "=> Dealer get " << a << " point," << endl;
	cout << "3 card from picking in deck for dealer: " << endl;
	while (tang < 3) 
	{
		for (int row = 0; row < SUITS; row++) 
		{
			for (int col = 0; col < FACES; col++)
			{
				if (deck[row][col] == (Po_left + tang)) 
				{
					se[dem1][0] = row;
					se[dem1][1] = col;
					printCard(faces[col], suits[row]);
					rowT = row;
					colT = col;
				}
			}
		}
		tang++;
		dem1++;
	}
	while (dem2 < 3 && dem == 1) 
	{
		for (int j = 0; j < 5 && Po_left < 3; j++) 
		{
			int temp1 = hand[j][0];
			int temp2 = hand[j][1];
			hand[j][0] = se[dem2][0];
			hand[j][1] = se[dem2][1];
			if (getStatusOfHand(hand) > 3) 
			{
				dem++;
				break;
			}
			else 
			{
				hand[j][0] = temp1;
				hand[j][1] = temp2;
			}
		}
		dem2++;
	}
	for (int j = 0; j < 5; j++) 
	{
		hands[0][j][0] = hand[j][0];
		hands[0][j][1] = hand[j][1];
	}
	if (dem == 0) 
	{
		int k, u;
		srand(time(NULL));
		k = rand() % 4 + 0;
		u = rand() % 2 + 0;
		hands[0][k][0] = se[u][0];
		hands[0][k][1] = se[u][1];
	}
	cout << endl << "5 new card after replace. " << endl;
	for (int i = 0; i < 5; i++) 
	{
		tempS = hands[0][i][0];
		tempR = hands[0][i][1];
		printCard(faces[tempR], suits[tempS]);
	}
	int b = getStatusOfHand(hand);
	cout << "=> Dealer get " << b << " point," << endl;
}

void Dealer(int deck[SUITS][FACES], int*** hands, int n) 
{
	int** hand = new int* [5];
	for (int i = 0; i < 5; i++) 
	{
		hand[i] = new int[2];
	}
	for (int j = 0; j < 5; j++) 
	{
		hand[j][0] = hands[0][j][0];
		hand[j][1] = hands[0][j][1];
	}
	const char suits[] = { 3,4, 5, 6 };
	const char* faces[] = { "A", "2","3","4","5","6","7","8","9","10","J","Q","K" };
	PickUpCardBetter(deck, hands, n, suits, faces);
}
