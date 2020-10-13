
#include"snake.h"





int main()
{
	initgraph(600, 500);
	Snake snake;
	while (1) {
		
		snake.drawall(snake);
		_kbhit;
		snake.Move(snake);
		snake.Chdir();
		Sleep(500);
	}
	return 0;
}

