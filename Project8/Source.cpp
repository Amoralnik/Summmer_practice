#include <iostream>
#include <conio.h>
#include "Functions.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	int size, top_step = 1000, amount_steps = -1,variable = 0;
	int** POLE_true;
	int pozition[2] = { 6,4 }, final[2] = { 10,8 };
	int** POLE1;
	int previous_x = pozition[1], previous_y = pozition[0];

	
	/*
	cout << pozition[0][1];-
	*/
	Input(size, "¬ведите размер пол€: ", 1, 100);
	size += 2;
	Sozdmatr(size, POLE_true);
	Sozdmatr(size, POLE1);	
	Initmatr2(POLE_true, size, -1, 2);
	Corners(size, POLE_true);
	Copy2(size, POLE_true, POLE1);

	Output2(POLE1, size);
	
	/*
	for (int i(0); i < size; i++)
	{
		if (i != 6)
			POLE_true[5][i] = 8;
	}
	POLE_true[1][3] = 8;
	POLE_true[1][2] = 8;
	POLE_true[3][2] = 8;
	POLE_true[2][1] = 8;
	POLE_true[2][3] = 8;
	POLE_true[final[0]][final[1]] = 0;
	POLE_true[6][7] = 0;
	*/
	/*
	Input(pozition[1], "Input start X:	", 1, size);
	Input(pozition[0], "Input start Y:	", 1, size);
	
	
	Input(final[1], "Input end X: ", 1, size); 
	Input(final[0], "Input end Y: ", 1, size);
	*/
	

	/*
	amount_move(POLE1, pozition, &begin);
	Output2(POLE1, size);
	chose_site(begin, pozition,amount_steps);
	//pozition[1]--;
	variable = amount_move(POLE1, pozition, &begin);
	//Output2(POLE1, size);
	if (!variable)
	{
		variable = unexpected_way(begin, POLE1, amount_steps,pozition);
		if (!variable)
		{
			cout << "\n\n\t\t NO MATCHES";
			exit(EXIT_SUCCESS);
		}
		amount_move(POLE1, pozition, &begin);
		chose_site(begin, pozition);
		variable =  amount_move(POLE1, pozition, &begin);
		Output2(POLE1, size);
	}
	else
	{
		chose_site(begin, pozition);
		variable = amount_move(POLE1, pozition, &begin);
		Output2(POLE1, size);
	}
	


	
	for (int i(0); i < 10; i++)
	{
		if (!variable)
		{
			variable = unexpected_way(begin, POLE1, amount_steps, pozition);
			if (!variable)
			{
				cout << "\n\n\t\t NO MATCHES";
				exit(EXIT_SUCCESS);
			}
			amount_move(POLE1, pozition, &begin);
			chose_site(begin, pozition);
			variable = amount_move(POLE1, pozition, &begin);
			Output2(POLE1, size);
		}
		else
		{
			chose_site(begin, pozition);
			variable = amount_move(POLE1, pozition, &begin);
			Output2(POLE1, size);
		}
	}
		variable = Find_way(begin, POLE1, pozition, final, size);
		top_step = variable;
		cout << "\n\n\n\n\n\nTOP STEP = " << top_step << "\n\n\n\n\n\n";
	*/
	variable = Find_way(POLE1, pozition, final, size);
	top_step = variable;
	cout << "\nTOP STEP = " << top_step << "\n\n\n\n\n\n";
		/*
	for (int i(0); i < 10; i++)
	{
		if (variable < top_step)
		{
			top_step = variable;
			cout << "\n\n\n\n\n\nTOP STEP = " << top_step << "\n\n\n\n\n\n";
		}

		DELETE(&begin);
	}
		*/
		

	return 0;
}