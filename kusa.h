#pragma once
#include"snake.h"
enum kusanum
{
	kusanum_1 = 10,kusanum_2=15,kusanum_3=20
};
class Kusa
{
public:
	Kusa();
	int kusa_x;
	int kusa_y;
	void drawkusa();
	void creatkusa(Snake* snake);
};

