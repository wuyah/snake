#include"Food.h"
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include<algorithm>

Food::Food()
{
	srand((int)time(0));

	m_x = -1;
	m_y = -1;
	m_state = false;
}
void Food::creatfood(Snake *snake,Kusa *kusap, int number) {
	int x=0;
	int y=0;
	while (!m_state)
	{
		x = (rand() % 27)*16+32;
		y = (rand() % 27)*16+32;
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
		bool cont1 = avoidkusa(x, y, number, kusap);
		if (cont&&cont1)
		{
			break;
		}
	}
		m_x = x;
		m_y = y;
		m_state = true;
		drawfood();
	}

void Food::creatfood2(Snake *snake, Kusa *kusap, int number) {
	int x = 0;
	int y = 0;
	while (!m_state)
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
		bool cont1 = avoidkusa(x, y, number, kusap);
		if (cont&&cont1)
		{
			break;
		}
	}
	m_x = x;
	m_y = y;
	m_state = true;
	drawfood2();
}


bool Food::avoidkusa(int x,int y,int number,Kusa *kusa) {
	bool cont = true;
	for (int i = 0; i <= number; i++) {
		int kusax = kusa->kusa_x;
		int kusay = kusa->kusa_y;
		if (x == kusax && y == kusay) {
			cont = false;
			break;
		}
		kusa++;
	}
	return cont;
}


void Food::drawfood() {
	setfillcolor(BLUE);
	setfillstyle(BS_SOLID);
	solidcircle(m_x, m_y, 6);
}
void Food::drawfood2() {
	setfillcolor(WHITE);
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