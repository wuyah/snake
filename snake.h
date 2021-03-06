#pragma once
#include<graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>

enum Direction { Dir_up = 1, Dir_right = 2, Dir_down = 3, Dir_left = 4 };//fangxiangcanshu



/////////////////////////定义蛇的节点和类

typedef struct Node //蛇的节点
{
	int x;
	int y;
	struct Node *next;
	struct Node *pre;
} SnakeBody;

class Snake //蛇的类
{
private:
	SnakeBody *head;
	SnakeBody *tail;
	int direction;
	int len;	   //节点数目


public:
	friend class Food;
	friend class Dilei;
	friend class Kusa;
	Snake();
	void Move(Snake&snake);
	int getlen();
	void Chdir(char ch);//改变方向
	void drawsnakebody(Node node);
	void drawsnakehead(Node node);
	void drawall(Snake snake);
	void clearsnakenode(Node node);


	bool collidesnake(const Snake snake);   //碰撞自身检测
	bool collidefood(int x,int y);
	bool collidewall();
	bool collidekusa(Kusa *kusap,int number);
	
	void eatfood(int x,int y);//吃东西
	void eatkusa();//吃雷
	void dead();
	void snakecutoff();


};