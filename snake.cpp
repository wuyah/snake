#include "snake.h"



////////////////////////////////////////////////////gouzaohanshu 
Snake::Snake() 
{
	SnakeBody* node1 = new SnakeBody;
	node1->next = NULL; node1->pre = NULL;
	node1->x = 132; node1->y = 132;
	SnakeBody * node2 = new SnakeBody;
	node2->next = node1; node1->pre = node2; node2->pre = NULL;
	node2->x = 116; node2->y = 132;
	SnakeBody * node3 = new SnakeBody;
	node3->next = node2; node2->pre = node3; node3->pre = NULL;
	node3->x = 100; node3->y = 132;

	head = node3; tail = node1;
	len = 2;
	direction = Dir_left;//构造长度为三的身体
}
void Snake::Move(Snake &snake) {
	Node nend;
	nend.x = tail->x;
	nend.y = tail->y;

	switch (direction) {
	case Dir_up:
		head->x = head->x; head->y = head->y - 16;
		drawsnakehead(*head);
		break;
	case Dir_down:
		head->x = head->x; head->y = head->y + 16;
		drawsnakehead(*head);

		break;
	case Dir_left:
		head->x = head->x - 16; head->y = head->y;
		drawsnakehead(*head);

		break;
	case Dir_right:
		head->x = head->x + 16; head->y = head->y;
		drawsnakehead(*head);

		break;

	default:
		drawsnakehead(*head);

		break;
	}
	SnakeBody *node = snake.tail;
	while (node != snake.head) //节点向前复制
	{
		node->x = node->pre->x;
		node->y = node->pre->y;
		node=node->pre;
	}

	clearsnakenode(nend);
}
void Snake::eatfood(int x,int y) {
	SnakeBody* Head = new  SnakeBody;
	Head->x = x; Head->y = y;
	Head->next = head;
	head->pre = Head;
	Head->pre = NULL;
	head = Head;
	++len;
}
void Snake::Chdir() {
	char ch;
	if (_kbhit() ){
		ch = _getch();
		switch (ch) {
		case'w':if ((direction != Dir_down) && (direction != Dir_up)) {
			direction = Dir_up;
		}break;
		case's':if ((direction != Dir_down) && (direction != Dir_up)) {
			direction = Dir_down;
		}break;
		case'a':if ((direction != Dir_right) && (direction != Dir_left)) {
			direction = Dir_left;
		}break;
		case'd':if ((direction != Dir_right) && (direction != Dir_left)) {
			direction = Dir_right;
		}break;
		}
		return;
	}
	else return;


		
	
}

void Snake::drawsnakebody(Node node)
{
	setfillcolor(RED);
	setfillstyle(BS_SOLID);
	solidrectangle(node.x - 8, node.y + 8, node.x + 8, node.y - 8);
}
void Snake::drawsnakehead(Node node) {
	setfillcolor(RED);
	setfillstyle(BS_SOLID);
	solidrectangle(node.x - 8, node.y + 8, node.x + 8, node.y - 8);
}

void Snake::drawall(Snake snake) {

	SnakeBody *linknode = snake.head;
	drawsnakehead(*linknode);//画头部
	linknode = linknode->next;

	while (linknode != snake.tail->next)
	{
		drawsnakebody(*linknode);
		linknode = linknode->next; 
	}
	


}
void Snake::coversnake(Node &node) {
	setfillcolor(BLACK);
	setfillstyle(BS_SOLID);
	solidrectangle(node.x - 8, node.y + 8, node.x + 8, node.y - 8);
}

void Snake::clearsnakenode(Node node)
{
	//黑色，全填充，无边框的正方形
	setfillcolor(BLACK);
	setfillstyle(BS_SOLID);
	solidrectangle(node.x - 9, node.y + 9, node.x + 9, node.y - 9);
}


void insert() {

}