#pragma once

#include"Food.h"
#include"snake.h"
#include"kusa.h"
#include"dilei.h"
#include <sstream>
#include<imapi.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <fstream>
using namespace std;

enum gamerunningstate{snake_dead = 0,snake_up = 1};

int gamerunning3(const int kusanum, const int sleeptime, int *scorep);


int beginclik();

//--------����------
void drawrunningui();
void drawbegin();
void drawdie();
void draw_wall();
void drawpause();
void drawscore(int score);
void drawlen(Snake snake);
void drawcongratulation();
//--------�����---------
void Savegame(int level);
int Loadgame();

//---------main------------
int main()
{
	initgraph(640, 480);//��ʼ������
	PlaySound("bgm.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC );
	while (1) {

		drawbegin();
		int mainui = beginclik();
		cleardevice();
		if (mainui == 1)//��ʼ��Ϸ
		{
			int score = 0;
			int *scorep = &score;
			int snakestate=1;
			snakestate=gamerunning3(kusanum_1, 250, &score);
			if (snakestate == 0) {
				cleardevice();
				continue;
			}
			snakestate=gamerunning3(kusanum_2, 200, &score);
			if (snakestate == 0) {
				cleardevice();
				continue;
			}
			snakestate=gamerunning3(kusanum_3, 150, &score);
			if (snakestate == 1) {
				cleardevice();
				drawcongratulation();
				char end = _getch();
				cleardevice();
				continue;
			}
			else {
				cleardevice();
				continue;
			}
			cleardevice();
		}
		if (mainui == 2)//��ȡ�浵
		{
			int level = 0;
			level=Loadgame();
			int score = 0;
			int snakestate=1;
			switch (level)
			{
			case kusanum_1:
				snakestate=gamerunning3(kusanum_1, 250, &score);
				if (snakestate == 0) {
					cleardevice();
					continue;
				}
			case kusanum_2:
				snakestate = gamerunning3(kusanum_2, 200, &score);
				if (snakestate == 0) {
					cleardevice();
					continue;
				}
			case kusanum_3:
				snakestate = gamerunning3(kusanum_3, 150, &score);
				if (snakestate == 1) {
					cleardevice();
					drawcongratulation();
					char end = _getch();
					cleardevice();
					continue;
				}
				break;
			default:
				break;
			}
			cleardevice();
		}
		
	}

	return 0;
}






int gamerunning3(const int kusanum, const int sleeptime, int * scorep) {
	int score0 = *scorep;//�̳з���
	bool restart = false;//�����ж�
	while (!snake_dead) 
	{
		int score = 0;
		switch (kusanum)
		{
		case kusanum_1:
			settextstyle(30, 0, "΢���ź�");
			settextcolor(RGB(230, 138, 238));
			outtextxy(250, 100, "�� һ ��");
			break;
		case kusanum_2:
			settextstyle(30, 0, "΢���ź�");
			settextcolor(RGB(230, 138, 238));
			outtextxy(250, 100, "�� �� ��");
			break;
		case kusanum_3:
			settextstyle(30, 0, "΢���ź�");
			settextcolor(RGB(230, 138, 238));
			outtextxy(250, 100, "�� �� ��");
			break;
		default:
			break;
		}//�жϹؿ�
		Sleep(1200);
		cleardevice();
		draw_wall();
		drawrunningui();
		Snake snake;
		snake.drawall(snake);//��ʼ���ߣ��Ժ���԰ѳ�ʼ����װ��һ�������У����Ӽ�ࣩ
		Kusa kusa[30];//��ʼ��kusa

		for (int i = 0; i <= kusanum; i++)//��ʼ��kusa
			//��kusa
		{
			kusa[i].creatkusa(&snake);
			if (i >= 1) {
				if (((kusa[i].kusa_x) == (kusa[i - 1].kusa_x)) && ((kusa[i].kusa_y) == (kusa[i - 1].kusa_y))) {
					i--;
				}
			}
		}
		Food food;
		Kusa* kusap;
		kusap = kusa;
		food.creatfood(&snake, kusap, kusanum);//��ʼ��food

		Dilei lei;//��ʼ����
		Point getf = food.getpoint(food);
		int food_x0 = getf.x;
		int food_y0 = getf.y;
		lei.creatlei(food_x0, food_y0, &snake, kusap, kusanum);//��ʼ�������Ϸ��ʼ
		bool food_state = food.exist();//����������������food����
		bool teleport_state = false;

		//ʳ������ָ��
		int x = 0;
		int y = 0;

		//����
		int poison = 0;
		//--------��ʽ������Ϸ-------------
		while (1)						
		{
			//-------������-------
			if (_kbhit()) 
			{
				char gamestate = _getch();
				switch (gamestate) {
				case'w':
					snake.Chdir('w');
					break;
				case's':
					snake.Chdir('s');
					break;
				case'a':
					snake.Chdir('a');
					break;
				case'd':
					snake.Chdir('d');
					break;
				case' ':
					drawpause();
					while (true) {
						if (_kbhit())
						{
							char state2 = _getch();
							if (state2 == ' ') {
								clearrectangle(500, 80, 640, 180);
								break;
							}
							if (state2 == 's') {
								Savegame(kusanum);
								clearrectangle(500, 80, 640, 180);
								break;
							}
						}
					}
					break;
				case 27:
					return snake_dead;

				}
			}
			snake.Move(snake);
			//-------����----------
			if (snake.getlen() == 0 || snake.collidewall() || snake.collidesnake(snake)||poison==3)//panduanshesil
			{

				cleardevice();
				while (true)
				{
					drawdie();
					char dead = _getch();
					if (dead == 27) //��esc�뿪�ؿ�
					{
						return snake_dead;
					}
					if (dead == 'r') //��r���¿�ʼ���ؿ�
					{
						restart = true;
						break;
					}
				}
				if (restart) {
					break;
				}
			}

			snake.drawall(snake);//����
			drawlen(snake);
		
			int *food_x= &x;
			int *food_y= &y;
			//--------������-------------
			if (snake.getlen() == 7 && !teleport_state) {
				food.beeaten();
				Food teleport;
				teleport_state = true;
				teleport.creatfood2(&snake, kusap, kusanum);
				Point getf = teleport.getpoint(teleport);
				*food_x = getf.x;
				*food_y = getf.y;
			}

			if (!teleport_state)
			{
				Point getf = food.getpoint(food);
				*food_x = getf.x;
				*food_y = getf.y;
			}
			
			

			//-----------һϵ�е���ײ���----------
			//--------�����ų��ֺ�׼�������κζ������Բ���������ֱ����------
			if (teleport_state && (snake.collidefood(lei.lei_x, lei.lei_y) || (snake.collidekusa(kusap, kusanum))))
			{
				cleardevice();
				drawdie();
				char dead = _getch();
				if (dead == 27) //��esc�뿪�ؿ�
				{
					return snake_dead;
				}
				if (dead == 'r') //��r���¿�ʼ���ؿ�
				{
					restart = true;
					break;
				}
			}
			//--------ʳ��------
			if (snake.collidefood(*food_x,* food_y))
			{
				snake.eatfood(*food_x, *food_y);
				if (snake.getlen()!=7) {
					Food();
					food.beeaten();
					food.creatfood(&snake, kusap, kusanum);
				}
			}
			//----��----
			if (snake.collidefood(lei.lei_x, lei.lei_y))//ײ�ף��ѳԶ����ļ���ù����ǳ���Ǹ��
			{
				if (snake.getlen() == 1) {
					cleardevice();
					drawdie();
					char dead = _getch();
					if (dead == 27) //��esc�뿪�ؿ�
					{
						return snake_dead;
					}
					if (dead == 'r') //��r���¿�ʼ���ؿ�
					{
						restart = true;
						break;
					}
				}
				snake.snakecutoff();
				lei.leibeeaten();
				Dilei();
				Point getf1 = food.getpoint(food);
				int f_x = getf1.x;
				int f_y = getf1.y;
				lei.creatlei(getf1.x, getf1.y, &snake, kusap, kusanum);
			}
			//-----------��-------------
			if (snake.collidekusa(kusap, kusanum))//chi cao
			{
				poison++;
				snake.eatkusa();
			}
			
			//------ͨ��--------
			score = score0 + snake.getlen() * 10;
			drawscore(score);
			
			//------------������һ��------------
			if (snake.getlen() == 8)
			{
				*scorep = score;
				restart = false;
				break;
			}
			Sleep(sleeptime);
		}
		if (!restart)
			break;
		cleardevice();
	}
	cleardevice();
	return snake_up;
}



int beginclik()
{
	while (true)
	{
		if (MouseHit())
		{
			MOUSEMSG mouse = GetMouseMsg();
			if (mouse.mkLButton)
			{
				if (mouse.x >= 270 && mouse.x <= 460 && mouse.y <= 270 && mouse.y >= 240)
				{
					FlushMouseMsgBuffer();
					return 1;
				}
				if (mouse.x >= 270 && mouse.x <= 460 && mouse.y <= 320 && mouse.y >= 280)
				{
					FlushMouseMsgBuffer();
					return 2;
				}
			}
		}
	}

}



void draw_wall() {
	setfillcolor(YELLOW);
	solidrectangle(0, 0, 16, 480);
	solidrectangle(0, 0, 480, 16);
	solidrectangle(480 - 16, 0, 480, 480);
	solidrectangle(0, 480 - 16, 480, 480);
}
void drawbegin() {
	settextcolor(RGB(255, 106, 106));
	settextstyle(60, 0, "΢���ź�");
	outtextxy(260, 100, "̰ �� ��");
	settextcolor(RGB(32, 178, 170));
	settextstyle(30, 0, "΢���ź�");
	outtextxy(270, 240, "��  ʼ  ��  Ϸ");
	settextcolor(RGB(230, 138, 238));
	outtextxy(270, 280, "��  ȡ  ��  ��");
	settextcolor(0x4EEE94);
	outtextxy(270, 340, "��*3 == die");
}
void drawdie() {
	settextcolor(RED);
	settextstyle(90, 0, "΢���ź�");
	outtextxy(200, 200, "�ˣ�");
	settextstyle(30, 0, "΢���ź�");
	outtextxy(200, 300, "�� esc �� ������ r �� �� �� ʼ");
}
void drawpause() {
	settextstyle(20, 0, "΢���ź�");
	settextcolor(WHITE);
	outtextxy(500, 100, "��ͣ��");
	outtextxy(500, 130, "����s'������Ȳ�����");
	outtextxy(500, 150, "���ո��������Ϸ");
}
void drawrunningui() {
	settextstyle(20, 0, "΢���ź�");
	settextcolor(RGB(138, 42, 246));
	outtextxy(500, 180, "�ϣ� ����");
	settextcolor(BLUE);
	outtextxy(500, 210, "����ʳ�� ");
	settextcolor(RGB(0, 205, 102));
	outtextxy(500, 240, "�̣� ����");
	settextcolor(WHITE);
	outtextxy(500, 260, "�ף� ������");
	outtextxy(500, 280, "�����ų��ֺ���ײ�κ�");
	outtextxy(500, 300, "����ֱ������");
	settextcolor(RGB(255,181,197));
	outtextxy(500, 320, "���ո����ͣ");
	outtextxy(500, 340, "��esc�ص�������");
}
void drawlen(Snake snake) {
	settextstyle(16, 0, "΢���ź�");
	settextcolor(WHITE);
	outtextxy(510, 360, "�����ȣ�");
	settextcolor(RGB(255, 85, 255));
	TCHAR t[5];
	_stprintf_s(t, _T("%d"), snake.getlen()); 
	outtextxy(560, 360, t);
}
void drawscore(int score) {
	settextstyle(16, 0, "΢���ź�");
	settextcolor(WHITE);
	outtextxy(510, 380, "��÷���");
	settextcolor(RGB(255, 85, 255));
	TCHAR t[5];
	_stprintf_s(t, _T("%d"), score);
	outtextxy(560, 380, t);
}
void drawcongratulation()
	{
	settextcolor(RED);
	settextstyle(90, 0, "΢���ź�");
	outtextxy(200, 200, "ֻ�����أ�������");
	settextstyle(50, 0, "����");
	outtextxy(200, 300, "�����������");
}

void Savegame(int level) {
	ofstream outfile;
	outfile.open("Save.txt", ios::out);
	if (!outfile.is_open())
	{
		printf("�浵������");
	}
	else
	{
		outfile << level;
	}
	return;
}
int Loadgame() {
	ifstream infile;
	infile.open("Save.txt", ios::in);
	int level=0;
	infile >> level;
	return level;
}