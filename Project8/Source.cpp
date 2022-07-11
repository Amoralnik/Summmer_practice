#include <iostream>
#include <conio.h>
#include "Functions.h"

using namespace std;
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

int amount_move(int**& POLE, int pozition[2], Chekpoint** begin, int final[])
{
	short max_move = 4;
	Chekpoint* n = new Chekpoint;


	if ((POLE[pozition[0] - 1][pozition[1]] != 0))
	{
		n->a.way_moves[0] = 0;
		max_move--;
	}
	if ((POLE[pozition[0]][pozition[1] + 1] != 0))
	{
		n->a.way_moves[1] = 0;
		max_move--;
	}
	if ((POLE[pozition[0] + 1][pozition[1]] != 0))
	{
		n->a.way_moves[2] = 0;
		max_move--;
	}
	if ((POLE[pozition[0]][pozition[1] - 1] != 0))
	{
		n->a.way_moves[3] = 0;
		max_move--;
	}

	if (max_move == 0 && (pozition[0] != final[0] && pozition[1] != final[1]))
	{
			POLE[pozition[0]][pozition[1]] = -1;
			n = NULL;
	} 
	else
	{
		POLE[pozition[0]][pozition[1]] = max_move;
		if (*begin == NULL)
		{
			n->a.X = pozition[1];
			n->a.Y = pozition[0];
			n->next = NULL;
			*begin = n;
		}
		else
		{
			Chekpoint* trash = *begin;
			while (trash->next)
				trash = trash->next;
			n->a.X = pozition[1];
			n->a.Y = pozition[0];
			trash->next = n;
			n->next = NULL;
		}
	}


	return max_move;
}

void chose_site(Chekpoint* begin, int pozition[], int final[], int& amount_steps)
{
	Chekpoint* n = begin;
	
	static int previous_x = -1, previous_y = -1;

	int variable[4];
	int j = 0;
	int result;
	
	/*
	if (n->a.X == previous_x && n->a.Y == previous_y)
	{
		
		
		return;
	}
	*/
	
	previous_x = n->a.X;
	previous_y = n->a.Y;
	while (n->next)
		n = n->next;
	if (pozition[1] < final[1] && n->a.way_moves[1])
		pozition[1]++;
	else if (pozition[1] > final[1] && n->a.way_moves[3])
		pozition[1]--;
	else if (pozition[0] > final[0] && n->a.way_moves[0])
		pozition[0]--;
	else if (pozition[0] < final[0] && n->a.way_moves[2])
		pozition[0]++;
	else
	{
		for (int i(0); i < 4; i++)
		{
			if (n->a.way_moves[i] == 1)
			{
				variable[j] = i;
				j++;
			}
		}
		if (j)
		{
			result = Randnumber(0, j - 1);
			switch (variable[result])
			{
			case 0: pozition[0]--;
				break;
			case 1: pozition[1]++;
				break;
			case 2: pozition[0]++;
				break;
			case 3: pozition[1]--;
				break;
			default: cout << "durak?";
				break;
			}
		}
	
	}
	amount_steps++;
	n->a.amount_moves = amount_steps;

}

bool unexpected_chek(int**& POLE, int pozition[], int final[])
{
	short max_move = 4;


	if ((POLE[pozition[0] - 1][pozition[1]] != 0))
		max_move--;
	if ((POLE[pozition[0]][pozition[1] + 1] != 0))
		max_move--;
	if ((POLE[pozition[0] + 1][pozition[1]] != 0))
		max_move--;
	if ((POLE[pozition[0]][pozition[1] - 1] != 0))
		max_move--;

	if (pozition[0] != final[0] || pozition[1] != final[1])
	{
	}

		if (max_move == 0)
			POLE[pozition[0]][pozition[1]] = -1;
		else
			POLE[pozition[0]][pozition[1]] = max_move;
	
	return max_move;
}

bool unexpected_way(Chekpoint* begin, int**& POLE, int& amount_steps, int pozition[], int final[])
{
	Chekpoint* n = begin;
	while (n != NULL)
	{
		pozition[0] = n->a.Y;
		pozition[1] = n->a.X;

		if (unexpected_chek(POLE, pozition,final))
		{
			amount_steps = n->a.amount_moves - 1;
			return 1;
		}
		n = n->next;
	}
	if (n == NULL)
	{
		return 0;
	}
}

void Smart_way(Chekpoint** begin, int& amount_steps, int**& POLE, int final[])
{
	Chekpoint* n = *begin;
	while (n)
	{
		Chekpoint* u = n;
		while (u)
		{
			while (u->a.amount_moves < 0 || n->a.amount_moves < 0)
			{
				if (u->a.amount_moves < 0)
					u = u->next;
				if (n->a.amount_moves < 0)
					n = n->next;
				continue;
			}
			if ((((u->a.X == n->a.X + 1) || (u->a.X == n->a.X - 1)) && u->a.Y == n->a.Y) && u->a.amount_moves > n->a.amount_moves + 1)
			{
				int variable = u->a.amount_moves - n->a.amount_moves;
				int variable1 = u->a.amount_moves;
				u->a.amount_moves = n->a.amount_moves + 1;
				Chekpoint* q = u;
				q = q->next;
				while (q)
				{
					if (q->a.amount_moves == ++variable1)
					{
						
						q->a.amount_moves -= variable;

					}
					//variable = q->a.amount_moves;
					q = q->next;
				}
				/*
				Chekpoint* lom = *begin;
				while (lom)
				{
					if (lom->a.amount_moves - variable > n->a.amount_moves)
					{
						lom->a.amount_moves -= variable;
						POLE[lom->a.Y][lom->a.X] = lom->a.amount_moves;
					}
					lom = lom->next;
				}
				*/
			}

			if ((((u->a.Y == n->a.Y + 1) || (u->a.Y == n->a.Y - 1)) && u->a.X == n->a.X) && u->a.amount_moves > n->a.amount_moves + 1)
			{		

				int variable = u->a.amount_moves - n->a.amount_moves - 1;
				int variable1 = u->a.amount_moves;
				u->a.amount_moves = n->a.amount_moves + 1;
				Chekpoint* q = u;
				q = q->next;
				while (q)
				{
					if (q->a.amount_moves == ++variable1)
					{

 						q->a.amount_moves -= variable;

					}
					//variable = q->a.amount_moves;
					q = q->next;
				}
				/*
				Chekpoint* lom = *begin;
				while (lom)
				{
					if (lom->a.amount_moves - variable > n->a.amount_moves)
					{
						lom->a.amount_moves -= variable;
						POLE[lom->a.Y][lom->a.X] = lom->a.amount_moves;
					}
					lom = lom->next;
				}
				*/
			}
			u = u->next;
		}

		n = n->next;
	}
	int variable = 0;
	Chekpoint* lom = *begin;
	while (lom)
	{
		if(lom->a.Y == final[0] && lom->a.X == final[1])
			amount_steps = lom->a.amount_moves;
		lom = lom->next;
	}
}

int Find_way(Chekpoint*& begin, int**& POLE1,int pozition[], int final[], int size)
{
	int amount_steps = -1;
	bool end = 0;
	/*
	*/
	if (pozition[0] == final[0] && pozition[1] == final[1])
	{
		cout << "\n\n\n\n\n\nTOP STEP = " << 0 << "\n\n\n\n\n\n";
		exit(EXIT_SUCCESS);
	}
	//do
	//{
		do
		{
			int variable;
			variable = unexpected_chek(POLE1, pozition, final);
			if (!variable)
			{
				variable = unexpected_way(begin, POLE1, amount_steps, pozition, final);
				if (!variable)
				{
					if (end == 0)
					{
						cout << "\n\n\t\t NO MATCHES";
						exit(EXIT_SUCCESS);
					}
					else
						break;
				}
				amount_move(POLE1, pozition, &begin, final);
				chose_site(begin, pozition, final, amount_steps);
				variable = unexpected_chek(POLE1, pozition, final);
				//Output2(POLE1, size);
			}
			else
			{
				amount_move(POLE1, pozition, &begin, final);
				chose_site(begin, pozition, final, amount_steps);
				variable = unexpected_chek(POLE1, pozition, final);
				//Output2(POLE1, size);
			}
			cout << "\n\n\namount_steps = " << amount_steps + 1 << "\n\n\n";
		} while ((pozition[0] != final[0]) || (pozition[1] != final[1]));
		end = 1;
	//} while (unexpected_way(begin, POLE1, amount_steps, pozition, final));
	//while ((pozition[0] != final[0]) || (pozition[1] != final[1]));
	amount_move(POLE1, pozition, &begin,final);
	
	Chekpoint* n = begin;
	while (n->next)
		n = n->next; 
	amount_steps++;
	n->a.amount_moves = amount_steps;
	//Output2(POLE1, size);
	cout << endl << endl;
	Smart_way(&begin, amount_steps, POLE1,final);
	
	Output2(POLE1, size);
	return amount_steps;
}


/*
*/




void DELETE(Chekpoint** begin)
{
	Chekpoint* n = *begin;
	while (n!= NULL)
	{
		*begin = n->next;
		n = NULL;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int size = 10, top_step = 1000, amount_steps = -1,variable = 0;
	int** POLE_true;
	int pozition[2] = { 2,3 }, final[2] = { 7,9 };
	int** POLE1;
	int previous_x = pozition[1], previous_y = pozition[0];
	Chekpoint* begin = NULL;
	
	/*
	cout << pozition[0][1];-
	*/
	//Input(size, "¬ведите размер пол€: ", 1, 100);
	size += 2;
	Sozdmatr(size, POLE_true);
	Sozdmatr(size, POLE1);	
	Initmatr2(POLE_true, size, -1, 2);
	
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
	*/
	POLE_true[2][3] = 8;
	POLE_true[final[0]][final[1]] = 0;


	POLE_true[6][7] = 0;

	
	Corners(size, POLE_true);
	Copy2(size, POLE_true, POLE1);
	//Output2(POLE1, size);
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
	variable = Find_way(begin, POLE1, pozition, final, size);
	top_step = variable;
	cout << "\n\n\n\n\n\nTOP STEP = " << top_step << "\n\n\n\n\n\n";
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