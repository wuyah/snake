#include "kusa.h"


Kusa::Kusa() {
	srand((int)time(0));
	kusa_x = -1;
	kusa_y = -1;
}

void Kusa::creatkusa(Snake* snake){
	int x;
	int y;
	while (1)
	{
		x = (rand() % 27) * 16 + 32;
		y = (rand() % 27) * 16 + 32;
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
	kusa_x = x;
	kusa_y = y;
	drawkusa();
}


void Kusa::drawkusa() {
	setfillcolor(RGB(0,205,102));
	setfillstyle(BS_SOLID);
	solidcircle(kusa_x, kusa_y ,6);
}

