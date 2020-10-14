#include"Food.h"
#include"snake.h"
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include<algorithm>

Food::Food()
{
	m_x = -1;
	m_y = -1;
	m_state = false;
}
void Food::creatfood( Snake *snake) {
	int x;
	int y;
	while (!m_state)
	{
		srand((int)time(0));
		x = (rand() % 12)*32+32;
		y = (rand() % 12)*32+32;
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
		m_x = x;
		m_y = y;
		m_state = true;
		drawfood();
	}



void Food::drawfood() {
	setfillcolor(BLUE);
	setfillstyle(BS_SOLID);
	solidcircle(m_x, m_y, 6);
}

void Food::clearfood() {
	clearcircle(m_x, m_y, 6);
	m_state = false;
}

bool Food::exist() {
	return m_state;
}

void Food::beeaten() {
	m_state = false;
}