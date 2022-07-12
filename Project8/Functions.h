#pragma once
#include <iostream>
#include <conio.h>

using namespace std;


/**
* Інформація про комірку
*
* @param х координата за х
* @param у координата за у
* @param way_moves можливіть піти у ту чи іншу сторну
* @param amount_moves кількість кроків до цієї комірки
* @return немає
*/
struct Cordinat
{
	int X;
	int Y;
	bool way_moves[4] = { 1,1,1,1 };
	int amount_moves;
};


/**
* Конект з іншою структурою
*
* @param a конект з іншою структурою
* @param next вкаівник на наступний єлемент структури
* @return немає
*/
struct Chekpoint
{
	Cordinat a;
	Chekpoint* next;
};

/**
* Перевірка на можливість руху
*
* @param pozition координти на момент часу 
* @param begin вказівник на початок списку
* @param final координати що шукаються
* @return кількість можливих кроків
*/
int amount_move(int** POLE, int pozition[2], Chekpoint** begin, int final[]);

/**
* Рухає кульку
*
* @param pozition координти на момент часу
* @param begin вказівник на початок списку
* @param final координати що шукаються
* @param amount_stesps кількість кроків що була зроблена
* @return немає
*/ 
void chose_site(Chekpoint** begin, int pozition[], int final[], int& amount_steps);

/**
* Перевірка на можливість руху
*
* @param POLE таблиця де проходять усі дії
* @param pozition координти на момент часу
* @param final координати що шукаються
* @return кількість можливих кроків
*/
bool unexpected_chek(int**& POLE, int pozition[], int final[]);

/**
* якщо немає можливості руху, переносить до останньго єлементу де він був можливим
*
* @param begin вказівник на початок списку
* @param POLE таблиця де проходять усі дії
* @param amount_steps кількість кроків що була зроблена
* @param pozition координти на момент часу
* @param final координати що шукаються
* @return чи був здіснений перехід(1 -так)
*/
bool unexpected_way(Chekpoint** begin, int**& POLE, int& amount_steps, int pozition[], int final[]);

/**
* Пошук більш короткого шляху
*
* @param begin вказівник на початок списку
* @param amount_steps кількість кроків що була зроблена
* @param POLE таблиця де проходять усі дії
* @param final координати що шукаються
* @return немає
*/
void Smart_way(Chekpoint** begin, int& amount_steps, int**& POLE, int final[]);

/**
* Упорядковує визов усіх необхідних фу-й
*
* @param begin вказівник на початок списку
* @param POLE1 таблиця де проходять усі дії
* @param pozition координти на момент часу
* @param final координати що шукаються
* @return чи був здіснений перехід(1 -так)
* @param size розмір таблиці
* @return найкращий результат за кількітю кроків
*/
int Find_way(int**& POLE1, int pozition[], int final[], int size);

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

/**
* Ініціалізація 2-вимірної таблиці випадковими числами
*
* @param matr таблиця що ініціалізується
* @param a рощмір таблиці
* @param min мінімальне допустиме значення
* @param max максимальне допустиме
* @return немає
*/
bool Initmatr2(int** matr, int a, int min, int max);

/**
* стврення 2-вимірноїї таблиці
*
* @param a розмір таблиці
* @param matr таблиця
* @return чи була створена(1 - так)
*/
bool Sozdmatr(int a, int**& matr);

/**
* Введення данних 
*
* @param a розмір таблиці
* @param matr таблиця
* @return немає
*/
void Output2(int** matr, int a);

/**
* Створення на попередньо разширеній таблиці координатної сітки
*
* @param a розмір
* @param matr таблиця
* @return чи була створена(1 - так)
*/
bool Corners(int a, int**& matr);

/**
* копіювання усіх значень з однієї матрці у іншу
*
* @param a розмір
* @param matr таблиця
* @param matr1 таблиця куди копіюють
* @return чи була скопійована(1 - так)
*/
bool Copy2(int a, int**& matr, int**& matr1);

/**
* генерація випадкового числа з границями
*
* @param min мінімально допустиме
* @param max максимально допустиме
* @return згенерроване число
*/
int Randnumber(int min, int max);
