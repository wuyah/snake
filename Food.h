#pragma once
#include"snake.h"
#include "kusa.h"
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
	friend class Kusa;
public:
	Food();
	void creatfood(Snake *snake,Kusa kusa[],int number);
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
	bool avoidkusa(int x,int y,int number,Kusa kusa[]);
};