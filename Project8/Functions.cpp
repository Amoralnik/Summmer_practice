#include <iostream>
#include <conio.h>
#include "Functions.h"

using namespace std;

void Input(int& a, string bob, double left, double right)
{

	if (left != 0 && right != 0)
	{
		while (true)
		{
			cout << bob;
			cin >> a;
			if (cin.fail() || (a < left || a > right))
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Error! Try again" << endl;
			}
			else
			{
				cin.ignore(32767, '\n');
				break;
			}

		}
	}

	else
	{
		while (true)
		{
			cout << bob;
			cin >> a;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Error! Try again" << endl;
			}
			else
			{
				cin.ignore(32767, '\n');
				break;
			}

		}
	}
}

void Initmatr2(int** matr, int a, int min, int max)
{
	const int C = min;
	const int B = max;
	//srand(time(NULL));
	for (int i(0); i < a; i++)
	{
		for (int j(0); j < a; j++)
		{
			int a = C + rand() % ((B + 1) - C);
			if (a != -1)
				matr[i][j] = 0;
			else
				matr[i][j] = 8;
		}
	}
}

void Sozdmatr(int a, int**& matr)
{
	matr = new int* [a];

	for (int i(0); i < a; i++)
	{
		matr[i] = new int[a] {};
	}
}

void Output2(int** matr, int a)
{
	for (int i(0); i < a; i++)
	{
		for (int j(0); j < a; j++)
		{
			if (j != a - 1)
			{

				if (matr[i][j] < 0)
					cout << " " << 0 << " | ";
				else if (matr[i][j] == 0)
					cout << "   | ";
				else if (matr[i][j] > 9)
					cout << matr[i][j] << " | ";
				else
					cout << " " << matr[i][j] << " | ";
			}
			else
					cout << " " << matr[i][j];

		}
		cout << endl;
		for (int i(0); i < a * 5 - 2; i++)
		{
			cout << "-";
		}
		cout << endl;
	}
	cout << endl;
}

void Init1_3(int***& matr)
{
	for (int i(0); i < 1; i++)
	{
		for (int j(0); j < 1; j++)
		{
			for (int k(0); k < 4; k++)
			{
				matr[i][j][k] = 1;
			}
		}
	}
}

void Corners(int a, int**& matr)
{
	for (int i(0); i < a; i++)
	{
		for (int j(0); j < a; j++)
		{
			if (i == 0 || i == a - 1)
				matr[i][j] = j;
			if (j == 0 || j == a - 1)
				matr[i][j] = i;
		}
	}
}

void Copy2(int a, int**& matr, int**& matr1)
{
	for (int i(0); i < a; i++)
	{
		for (int j(0); j < a; j++)
		{
			matr1[i][j] = matr[i][j];
		}
	}
}

void Sozdmatr3(int a, int***& matr)
{
	matr = new int** [a];

	for (int i(0); i < a; i++)
	{
		matr[i] = new int* [a] {};
		for (int j(0); j < a; j++)
		{
			matr[i][j] = new int[4]{};
		}
	}
}

int Randnumber(int min, int max)
{
	const int C = min;
	const int B = max;
	srand(time(NULL));
	int a;
	a = C + rand() % ((B + 1) - C);

	return a;
}