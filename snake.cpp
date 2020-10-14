#include "Food.h"
#include"snake.h"


////////////////////////////////////////////////////gouzaohanshu 
Snake::Snake() 
{
	SnakeBody* node1 = new SnakeBody;
	node1->next = NULL; node1->pre = NULL;
	node1->x = 320; node1->y = 320;
	SnakeBody * node2 = new SnakeBody;
	node2->next = node1; node1->pre = node2; node2->pre = NULL;
	node2->x = 352; node2->y = 320;
	SnakeBody * node3 = new SnakeBody;
	node3->next = node2; node2->pre = node3; node3->pre = NULL;
	node3->x = 384; node3->y = 320;

	head = node3; tail = node1;
	len = 2;
	direction = Dir_left;//构造长度为三的身体
}
void Snake::Move(Snake &snake) {
	SnakeBody nend;
	nend.x = tail->x;
	nend.y = tail->y;
	nend.next = tail->next;
	nend.pre = tail->pre;

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
	solidrectangle(node.x - 7, node.y + 7, node.x + 7, node.y - 7);
}
void Snake::drawsnakehead(Node node) {
	setfillcolor(RED);
	setfillstyle(BS_SOLID);
	solidrectangle(node.x - 7, node.y + 7, node.x + 7, node.y - 7);
}

void Snake::drawall(Snake snake) {

	SnakeBody *linknode = snake.head;

	linknode = linknode->next;
	drawsnakebody(*linknode);

	while (linknode != snake.tail->next)
	{
		drawsnakebody(*linknode);
		linknode = linknode->next; 
	}
	drawsnakebody(*snake.tail);


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


void Snake::eatfood(int x,int y) {
	SnakeBody* nodes = (SnakeBody*)malloc(sizeof(Node));
	nodes->x = x;
	nodes->y = y;
	nodes->next = tail->next;
	nodes->pre = tail;
	tail->next = nodes;
	tail = nodes;
	len++;
}

bool Snake::collidefood(int x,int y) {
	bool collide = false;
	if ((head->x==x)&&(head->y==y)) {
		collide = true;
	}
	return collide;
}
bool Snake::collidesnake(const Snake snake) {
	Node *node = snake.head;
	bool collide =false;
	while (node != snake.tail->next) {
		if (node->x == snake.head->x&&node->y == snake.head->y) {
			collide = true;
			break;
		}
		node = node->next;
		return collide;
	}
}