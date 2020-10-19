#pragma once
#include"snake.h"
#include"kusa.h"
class Dilei {
public:
	friend class snake;
	friend class Kusa;
	int lei_x;
	int lei_y;
	bool lei_state;
	Dilei();
	void leibeeaten();
	void creatlei(int x,int y,Snake *snake, Kusa* kusap, int number);//Éú³ÉµØÀ×
	void drawlei();
	bool avoidkusa(int x, int y, int number, Kusa* kusap);
};
