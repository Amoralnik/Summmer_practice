#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

/**
* Введення данних із перевіркою правильності вводу
*
* @param a число
* @param bob надпис при введені данних
* @param left мінімальне допустиме значення
* @param right максимальне допустиме
* (якщо left, right = 0, то обмежень немає)
* @return немає
*/
struct Cordinat
{
	int X;
	int Y;
	bool way_moves[4] = { 1,1,1,1 };
	int amount_moves;
};


struct Chekpoint
{
	Cordinat a;
	Chekpoint* next;
};

int amount_move(int** POLE, int pozition[2], Chekpoint** begin, int final[]);

void chose_site(Chekpoint** begin, int pozition[], int final[], int& amount_steps);

bool unexpected_chek(int**& POLE, int pozition[], int final[]);

bool unexpected_way(Chekpoint** begin, int**& POLE, int& amount_steps, int pozition[], int final[]);

void Smart_way(Chekpoint** begin, int& amount_steps, int**& POLE, int final[]);

int Find_way(Chekpoint** begin, int**& POLE1, int pozition[], int final[], int size);

void Input(int& a, string bob, double left, double right);

void Initmatr2(int** matr, int a, int min, int max);

void Sozdmatr(int a, int**& matr);

void Output2(int** matr, int a);

void Init1_3(int***& matr);

void Corners(int a, int**& matr);

void Copy2(int a, int**& matr, int**& matr1);

void Sozdmatr3(int a, int***& matr);

int Randnumber(int min, int max);