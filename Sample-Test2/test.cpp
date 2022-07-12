#include "pch.h"
#include <iostream>
#include "..\Project8\Functions.cpp"



int b = 12, top_step = 1000, amount_steps = -1, variable = 0;
int pozition[2] = { 6,4 }, final[2] = { 1,1 };
int** POLE1;
int previous_x = pozition[1], previous_y = pozition[0];



TEST(TestSozdMatr, TestEnough) {
  EXPECT_EQ(Sozdmatr(b, POLE1), 1);
}
TEST(TestInitialization, Test1)
{
	EXPECT_EQ(Initmatr2(POLE1, b, -1, 2), 1);
}
TEST(TestSetka, Test1)
{
	EXPECT_EQ(Corners(b, POLE1), 1);
}
/*
TEST(TestAmount_steps, Test1)
{
	EXPECT_EQ(Find_way(POLE1, pozition, final, b), 8);
}
*/

/*
TEST(TestAmount_steps, Test2)
{
	final[0] = 10;
	final[1] = 1;
	EXPECT_EQ(Find_way(POLE1, pozition, final, b), 7);
}
*/

TEST(TestAmount_steps, Test3)
{
	final[0] = 10;
	final[1] = 8;
	EXPECT_EQ(Find_way(POLE1, pozition, final, b), 8);
}
