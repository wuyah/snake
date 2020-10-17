#pragma once

#include"Food.h"

class Dilei {
public:
	friend class snake;
	friend class Kusa;
	int lei_x;
	int lei_y;
	bool lei_state;
	Dilei();
	void leibeeaten();
	void creatlei(int x,int y,Snake *snake);//Éú³ÉµØÀ×
	void drawlei();
};
