#pragma once
#include <iostream>
#include <conio.h>

using namespace std;


/**
* ���������� ��� ������
*
* @param � ���������� �� �
* @param � ���������� �� �
* @param way_moves �������� ��� � �� �� ���� ������
* @param amount_moves ������� ����� �� ���� ������
* @return ����
*/
struct Cordinat
{
	int X;
	int Y;
	bool way_moves[4] = { 1,1,1,1 };
	int amount_moves;
};


/**
* ������ � ����� ����������
*
* @param a ������ � ����� ����������
* @param next ������� �� ��������� ������� ���������
* @return ����
*/
struct Chekpoint
{
	Cordinat a;
	Chekpoint* next;
};

/**
* �������� �� ��������� ����
*
* @param pozition ��������� �� ������ ���� 
* @param begin �������� �� ������� ������
* @param final ���������� �� ���������
* @return ������� �������� �����
*/
int amount_move(int** POLE, int pozition[2], Chekpoint** begin, int final[]);

/**
* ���� ������
*
* @param pozition ��������� �� ������ ����
* @param begin �������� �� ������� ������
* @param final ���������� �� ���������
* @param amount_stesps ������� ����� �� ���� ��������
* @return ����
*/ 
void chose_site(Chekpoint** begin, int pozition[], int final[], int& amount_steps);

/**
* �������� �� ��������� ����
*
* @param POLE ������� �� ��������� �� 䳿
* @param pozition ��������� �� ������ ����
* @param final ���������� �� ���������
* @return ������� �������� �����
*/
bool unexpected_chek(int**& POLE, int pozition[], int final[]);

/**
* ���� ���� ��������� ����, ���������� �� ��������� �������� �� �� ��� ��������
*
* @param begin �������� �� ������� ������
* @param POLE ������� �� ��������� �� 䳿
* @param amount_steps ������� ����� �� ���� ��������
* @param pozition ��������� �� ������ ����
* @param final ���������� �� ���������
* @return �� ��� �������� �������(1 -���)
*/
bool unexpected_way(Chekpoint** begin, int**& POLE, int& amount_steps, int pozition[], int final[]);

/**
* ����� ���� ��������� �����
*
* @param begin �������� �� ������� ������
* @param amount_steps ������� ����� �� ���� ��������
* @param POLE ������� �� ��������� �� 䳿
* @param final ���������� �� ���������
* @return ����
*/
void Smart_way(Chekpoint** begin, int& amount_steps, int**& POLE, int final[]);

/**
* ���������� ����� ��� ���������� ��-�
*
* @param begin �������� �� ������� ������
* @param POLE1 ������� �� ��������� �� 䳿
* @param pozition ��������� �� ������ ����
* @param final ���������� �� ���������
* @return �� ��� �������� �������(1 -���)
* @param size ����� �������
* @return ��������� ��������� �� ������ �����
*/
int Find_way(int**& POLE1, int pozition[], int final[], int size);

/**
* �������� ������ �� ��������� ����������� �����
*
* @param a �����
* @param bob ������ ��� ������ ������
* @param left �������� ��������� ��������
* @param right ����������� ���������
* (���� left, right = 0, �� �������� ����)
* @return ����
*/
void Input(int& a, string bob, double left, double right);

/**
* ����������� 2-������ ������� ����������� �������
*
* @param matr ������� �� ������������
* @param a ����� �������
* @param min �������� ��������� ��������
* @param max ����������� ���������
* @return ����
*/
bool Initmatr2(int** matr, int a, int min, int max);

/**
* �������� 2-����� �������
*
* @param a ����� �������
* @param matr �������
* @return �� ���� ��������(1 - ���)
*/
bool Sozdmatr(int a, int**& matr);

/**
* �������� ������ 
*
* @param a ����� �������
* @param matr �������
* @return ����
*/
void Output2(int** matr, int a);

/**
* ��������� �� ���������� ��������� ������� ����������� ����
*
* @param a �����
* @param matr �������
* @return �� ���� ��������(1 - ���)
*/
bool Corners(int a, int**& matr);

/**
* ��������� ��� ������� � ���� ������ � ����
*
* @param a �����
* @param matr �������
* @param matr1 ������� ���� �������
* @return �� ���� ����������(1 - ���)
*/
bool Copy2(int a, int**& matr, int**& matr1);

/**
* ��������� ����������� ����� � ���������
*
* @param min �������� ���������
* @param max ����������� ���������
* @return ������������ �����
*/
int Randnumber(int min, int max);
