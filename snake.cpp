#include"snake.h"
#include"kusa.h"
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
	len = 1;
	direction = Dir_left;//构造长度为一的身体
}
//----------------动！----------------------
void Snake::Move(Snake &snake) {
	SnakeBody nend;//继承尾节点
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
//变个方向

void Snake::Chdir(char ch) {
	
		switch (ch) {
		case'w':
			if ((direction != Dir_down) && (direction != Dir_up)) {
			direction = Dir_up;
		}break;
		case's':
			if ((direction != Dir_down) && (direction != Dir_up)) {
			direction = Dir_down;
		}
			break;
		case'a':
			if ((direction != Dir_right) && (direction != Dir_left)) {
			direction = Dir_left;
		}
			break;
		case'd':
			if ((direction != Dir_right) && (direction != Dir_left)) {
			direction = Dir_right;
		}break;
		}
		return;
	
}

int Snake::getlen() {
	return len;
}



//--------------画画-----------------------

void Snake::drawsnakebody(Node node)
{
	setfillcolor(RED);
	setfillstyle(BS_SOLID);
	solidrectangle(node.x - 7, node.y + 7, node.x + 7, node.y - 7);
}
void Snake::drawsnakehead(Node node) {
	setfillcolor(RGB(205,201,165));
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

void Snake::clearsnakenode(Node node)
{
	clearrectangle(node.x - 9, node.y + 9, node.x + 9, node.y - 9);
}

//-----------吃各种东西--------------
void Snake::eatfood(int x, int y) {
	SnakeBody* nodes = (SnakeBody*)malloc(sizeof(Node));
	nodes->x = x;
	nodes->y = y;
	nodes->next = tail->next;
	nodes->pre = tail;
	tail->next = nodes;
	tail = nodes;
	len++;
}
void Snake::eatkusa() {
	clearrectangle(tail->x - 9, tail->y + 9, tail->x + 9, tail->y - 9);
	Node* lnode =tail->pre;
	delete tail;
	tail = lnode;
	tail->next = nullptr;
	len--;
}

void Snake::snakecutoff() {
	if (len < 2) {
		dead();
	}
	else {
		int lenth = len;
		for (int i = 1; i <= lenth / 2; i++) {

			eatkusa();
		}
	}
}

void Snake::dead() {
	cleardevice();
}

//-------------碰撞检测-----------
bool Snake::collidefood(int x, int y) {
	bool collide = false;
	if ((head->x == x) && (head->y == y)) {
		collide = true;
	}
	return collide;
}
bool Snake::collidesnake(const Snake snake) {
	Node *node = snake.head->next->next;
	bool collide = false;
	while (node != snake.tail->next) {
		if ((node->x == snake.head->x) && (node->y == snake.head->y)) {
			collide = true;
			break;
		}
		node = node->next;
	}
	return collide;
}//碰撞检测
bool Snake::collidekusa(Kusa * kusap,int number) {
	bool collide = false;
	for (int i = 0; i <= number; i++) {
		int x = kusap->kusa_x;
		int y = kusap->kusa_y;
		if ((head->x == x) && (head->y == y)) {
			collide = true;
			kusap->kusa_x = -1;
			kusap->kusa_y = -1;
			break;
		}
		kusap++;
	}
	return collide;
}

bool Snake::collidewall(){
	Node*node = head;
	bool collide = false;
	node->x = head->x;
	node->y = head->y;
	if ((node->x - 7) < 16 || (node->x + 7) > 464 || (node->y - 7) < 16 || (node->y + 7) > 464)
	{
		collide = true;
	}
	
return collide;
}

