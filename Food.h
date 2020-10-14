#pragma once
#include"snake.h"
struct Point
{
	int x;
	int y;
}; 



class Food{
private:
	int m_x;
	int m_y;
	bool m_state;
	friend class Snake;
public:
	Food();
	void creatfood(Snake *snake);
	void drawfood();
	Point getpoint(Food food) {
		Point getf;
		getf.x = m_x;
		getf.y = m_y;
		return  getf;
	}
	void clearfood();
	bool exist();
	void beeaten();
};