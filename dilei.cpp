#include"dilei.h"

Dilei::Dilei() {
	srand((int)time(0));

	lei_x = -1;
	lei_y = -1;
	lei_state = false;
}

void Dilei::drawlei() {
	setfillcolor(RGB(138,42,246));
	setfillstyle(BS_SOLID);
	solidcircle(lei_x, lei_y, 6);
}
void Dilei::creatlei(int f_x,int f_y,Snake *snake) {
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
		if (cont)
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

