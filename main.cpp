#pragma once

#include"Food.h"
#include"dilei.h"
#include "kusa.h"
#include <vector>

using namespace std;

void draw_wall();
void gamerunning1();



int main()
{
	initgraph(640, 480);//��ʼ������
	char chooseguanqia = _getch();
		if (chooseguanqia=='1'){
			gamerunning1();
		}
			
	return 0;
}





void gamerunning1() {
	outtextxy(320, 240, "��һ��");
	Sleep(500);
	cleardevice();
	draw_wall();
	Snake snake;
	snake.drawall(snake);//��ʼ���ߣ��Ժ���԰ѳ�ʼ����װ��һ�������У����Ӽ�ࣩ
	Kusa kusa[kusanum_1];//��ʼ��kusa

	for (int i = 0; i <= kusanum_1; i++) {
		kusa[i].creatkusa(&snake);
		if (i >= 1) {
			if (((kusa[i].kusa_x) == (kusa[i - 1].kusa_x)) && ((kusa[i].kusa_y) == (kusa[i - 1].kusa_y))) {
				i--;
			}
		}
	}
	Kusa *kusap = &kusa[0];
	Food food;
	food.creatfood(&snake, kusap, kusanum_1);//��ʼ��food

	Dilei lei;//��ʼ����
	Point getf = food.getpoint(food);
	int food_x0 = getf.x;
	int food_y0 = getf.y;
	lei.creatlei(food_x0, food_y0, &snake);//��ʼ�������Ϸ��ʼ
	bool food_state = food.exist();//����������������food����
	while (1) {
		snake.Chdir();
		snake.Move(snake);
		if (snake.collidesnake(snake)) //ײ�Լ�
		{
			setfillcolor(BLUE);
			setfillstyle(BS_SOLID);
			solidcircle(500, 300, 18);
		}
		if (snake.collidewall())//ײǽ
		{
			setfillcolor(RED);
			setfillstyle(BS_SOLID);
			solidcircle(600, 300, 18);
		}
		snake.drawall(snake);//����
		Point getf = food.getpoint(food);
		int food_x = getf.x;
		int food_y = getf.y;
		if (snake.collidefood(food_x, food_y)) {
			snake.eatfood(food_x, food_y);
			food.beeaten();
			Food();
			food.creatfood(&snake, kusap, kusanum_1);
		}
		if (snake.collidefood(lei.lei_x, lei.lei_y))//ײ�ף��ѳԶ����ļ���ù����ǳ���Ǹ��
		{
			snake.snakecutoff();
			lei.leibeeaten();
			Dilei();
			Point getf1 = food.getpoint(food);
			int f_x = getf1.x;
			int f_y = getf1.y;
			lei.creatlei(getf1.x, getf1.y, &snake);
		}

		Sleep(300);
	}
}

void draw_wall(){
	setfillcolor(YELLOW);
	solidrectangle(0, 0, 16, 480);
	solidrectangle(0, 0, 480, 16);
	solidrectangle(480 - 16, 0, 480, 480);
	solidrectangle(0, 480 - 16, 480, 480);
}
