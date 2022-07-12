
#include "pch.h"
#include "..\Project8\Functions.cpp"


int top_step = 1000, amount_steps = -1, variable = 0;
int** POLE_true;
int pozition[2] = { 2,3 }, final[2] = { 7,9 };
int** POLE1;
int previous_x = pozition[1], previous_y = pozition[0];
int size = 12;

Sozdmatr(size, POLE_true);
Sozdmatr(size, POLE1);
Initmatr2(POLE_true, size, -1, 2);
Corners(size, POLE_true);
Copy2(size, POLE_true, POLE1);

Output2(POLE1, size);


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}