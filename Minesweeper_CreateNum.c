#include <stdio.h>

int main()
{
	int n = 0, m = 0, count = 0, now = 0;
	char mine[100][100];

	while (1)
	{
		now++;
		scanf_s("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf_s(" %c", &mine[i][j], 1);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mine[i][j] != '*')
				{
					count = 0;
					if (i + 1 < n)
					{
						if (j + 1 < m)
							if (mine[i + 1][j + 1] == '*')
								count++;
						if (j - 1 >= 0)
							if (mine[i + 1][j - 1] == '*')
								count++;
						if (mine[i + 1][j] == '*')
							count++;
					}
					if (i - 1 >= 0)
					{
						if (j + 1 < m)
							if (mine[i - 1][j + 1] == '*')
								count++;
						if (j - 1 >= 0)
							if (mine[i - 1][j - 1] == '*')
								count++;
						if (mine[i - 1][j] == '*')
							count++;
					}
					if (j + 1 < m)
						if (mine[i][j + 1] == '*')
							count++;
					if (j - 1 >= 0)
						if (mine[i][j - 1] == '*')
							count++;
					mine[i][j] = count + '0';
				}
			}
		}
		printf("Field #%d:\n", now);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				printf("%c", mine[i][j]);
			printf("\n");
		}
	}

	return 0;
}
