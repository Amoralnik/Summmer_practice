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
void Input(int& a, string bob, double left, double right);

void Initmatr2(int** matr, int a, int min, int max);

void Sozdmatr(int a, int**& matr);

void Output2(int** matr, int a);

void Init1_3(int***& matr);

void Corners(int a, int**& matr);

void Copy2(int a, int**& matr, int**& matr1);

void Sozdmatr3(int a, int***& matr);

int Randnumber(int min, int max);