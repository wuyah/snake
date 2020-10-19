#include"dilei.h"

Dilei::Dilei() {
	srand((int)time(0));

	lei_x = -1;
	lei_y = -1;
	lei_state = false;
}


void Dilei::creatlei(int f_x,int f_y,Snake *snake,Kusa* kusa,int number) {
	int x;
	int y;
	while (!lei_state)
	{
		x = (rand() % 27) * 16 +32;
		y = (rand() % 27) * 16 +32;
		if (f_x == x && f_y == y) {
			x = (rand() % 27) * 16+32;
			y = (rand() % 27) * 16 +32;
		}
		SnakeBody*node = snake->head;
		bool cont = true;
		while (node != snake->tail->next)
		{
			if (node->x == x && node->y == y)
			{
				cont = false;
				break;
			}
			node = node->next;
		}
		bool cont1= avoidkusa(x, y, number, kusa);
		if (cont&&cont1)
		{
			break;
		}
	}
	lei_x = x;
	lei_y = y;
	lei_state = true;
	drawlei();
}

void Dilei::leibeeaten() {
	lei_state = false;
}

bool Dilei::avoidkusa(int x, int y, int number, Kusa *kusap) {
	bool cont = true;
	
	for (int i = 0; i <= number; i++) {
		int kusax = kusap->kusa_x;
		int kusay = kusap->kusa_y;
		if (x == kusax && y == kusay) {
			cont = false;
			break;
		}
		kusap++;
	}
	return cont;
}

void Dilei::drawlei() {
	setfillcolor(RGB(138, 42, 246));
	setfillstyle(BS_SOLID);
	solidcircle(lei_x, lei_y, 6);
}