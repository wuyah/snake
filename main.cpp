#pragma once

#include"Food.h"




int main()
{
	initgraph(600, 500);
	Snake snake;
	Food food;
	food.creatfood(&snake);
	bool food_state = food.exist();
	while (1) {
		
		
		snake.Chdir();
		snake.Move(snake);
		snake.drawall(snake);		
		
		
		Point getf = food.getpoint(food);
		int food_x = getf.x;
		int food_y = getf.y;
		if (snake.collidefood(food_x,food_y)) {
			snake.eatfood(food_x,food_y);
			food.beeaten();
			Food();
			food.creatfood(&snake);
		}
		Sleep(300);
	}
	return 0;
}

