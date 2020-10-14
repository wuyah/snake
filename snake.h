#pragma once
#include<graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
#include"Food.h"


enum Direction { Dir_up = 1, Dir_right = 2, Dir_down = 3, Dir_left = 4 };//fangxiangcanshu



/////////////////////////�����ߵĽڵ����

typedef struct Node //�ߵĽڵ�
{
	int x;
	int y;
	struct Node *next;
	struct Node *pre;
} SnakeBody;

class Snake //�ߵ���
{
private:
	SnakeBody *head;
	SnakeBody *tail;
	int direction;
	int len;	   //�ڵ���Ŀ


public:
	friend class Food;
	Snake();
	void Move(Snake&snake);
	//int getlen();
	void Chdir();//�ı䷽��
	void drawsnakebody(Node node);
	void drawsnakehead(Node node);
	bool collidesnake(const Snake snake);   //��ײ������
	bool collidefood(int x,int y);
	void drawall(Snake snake);
	void coversnake(Node &node);
	void clearsnakenode(Node node);
	void eatfood(int x,int y);
};