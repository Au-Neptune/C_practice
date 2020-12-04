#include <stdio.h>

int main()
{
	int num;
	while(scanf("%d",&num) != EOF)
	{
		if( num%400==0 || (num%4==0 && num%100!=0))
			puts("¶|¦~");
		else
			puts("¥­¦~");
	}
	return 0;
}

