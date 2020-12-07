#include <stdio.h>

int face = 0;	//0右 1下 2左 3上

int main()
{
	char maze[12][12];
	int start_x = 0, start_y = 0, x = 0, y = 0;

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
			scanf_s(" %c", &maze[i][j], 1);
		if (maze[i][0] == 'X')
			start_y = i;
	}
	maze[start_y][0] = 'R';
	y = start_y;

	while (x != 11)
	{
		switch (face)
		{
		case 0:
			if (maze[y][x + 1] != '#')	//向右
			{
				x += 1;
				maze[y][x] = 'R';
				face = 1;
			}
			else
				face = 3;
			break;
		case 1:
			if (maze[y + 1][x] != '#')	//向下
			{
				y += 1;
				maze[y][x] = 'R';
				face = 2;
			}
			else
				face = 0;
			break;
		case 2:
			if (maze[y][x - 1] != '#')	//向左
			{
				x -= 1;
				maze[y][x] = 'R';
				face = 3;
			}
			else
				face = 1;
			break;
		case 3:
			if (maze[y - 1][x] != '#')	//向上
			{
				y -= 1;
				maze[y][x] = 'R';
				face = 0;
			}
			else
				face = 2;
			break;
		}
		if (x == start_x && y == start_y)
		{
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 12; j++)
					printf("%c", maze[i][j]);
				printf("\n");
			}
			printf("This maze has no solution");
			return 0;
		}
	}
	
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++)
			printf("%c", maze[i][j]);
		printf("\n");
	}
	return 0;
}
