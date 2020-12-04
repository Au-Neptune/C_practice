#include <stdio.h>
#include <string.h>

int c_int[30], c_flo[30];
int check = 0;

void Add(int a_int[], int a_flo[], int b_int[], int b_flo[])
{	
	//计
	for (int i = 29; i >= 0; i--)
	{
		c_flo[i] += (a_flo[i] + b_flo[i]) % 10;
		if (a_flo[i] + b_flo[i] >= 10 && i - 1 >= 0)
			c_flo[i - 1] += 1;
		else if (a_flo[i] + b_flo[i] >= 10)
			c_int[29] += 1;
	}
	//俱计
	for (int i = 29; i >= 0; i--)
	{
		if (c_int[i] + a_int[i] + b_int[i] >= 10)
			c_int[i - 1] += 1;
		c_int[i] = (c_int[i] + a_int[i] + b_int[i]) % 10;
		//printf("%d\n", c_int[i]);
	}
}

void Minus(int a_int[], int a_flo[], int b_int[], int b_flo[])
{
	int ctx = 0;
	//搭计
	for (int i = 29; i >= 0; i--)
	{
		if (a_flo[i] - b_flo[i] - ctx < 0)
		{
			c_flo[i] = (a_flo[i] + 10) - b_flo[i] - ctx;
			ctx = 1;
		}
		else
		{
			c_flo[i] = a_flo[i] - b_flo[i] - ctx;
			ctx = 0;
		}
		//printf("%d", c_flo[i]);
	}
	//puts("");
	//搭俱计
	for (int i = 29; i >= 0; i--)
	{
		if (a_int[i] - b_int[i] - ctx < 0)
		{
			c_int[i] = (a_int[i] + 10) - b_int[i] - ctx;
			ctx = 1;
		}
		else
		{
			c_int[i] = a_int[i] - b_int[i] - ctx;
			ctx = 0;
		}
		//printf("%d", c_int[i]);
	}
	//puts("");
}

int main()
{
	char input[150];
	int a_int[30], a_flo[30], b_int[30], b_flo[30];
	int num, now = 0;

	scanf_s("%d", &num);
	while (now < num)
	{
		int sym = 0, ap = 0, bp = 0, input_len = 0, flag = 0, point = -1;
		check = 0;
		for (int i = 0; i < 30; i++)
		{
			a_int[i] = 0;
			a_flo[i] = 0;
			b_int[i] = 0;
			b_flo[i] = 0;
			c_int[i] = 0;
			c_flo[i] = 0;
		}
		scanf_s("%s", input, 150);
		input_len = strlen(input);

		//sym搭才腹瞷皚材碭じ
		if(strchr(input, '+') != NULL)
			sym = strchr(input, '+') - input;
		else
			sym = strchr(input, '-') - input;

		//ap㎝bp计翴Τ碭(Τ1)
		for (int i = 0; i < sym; i++)
			if (input[i] == '.')
				ap = sym - i;
		for (int i = sym + 1; i < input_len; i++)
			if (input[i] == '.')
				bp = input_len - i;
		//printf("ap:%d  bp:%d\n", ap, bp);

		int temp = 1;
		while (temp <= 30)
		{
			//俱计
			if (sym - ap - temp < 0)
				a_int[30 - temp] = 0;
			else
				a_int[30 - temp] = input[sym - ap - temp] - '0';

			if (input_len - bp - temp <= sym)
				b_int[30 - temp] = 0;
			else
				b_int[30 - temp] = input[input_len - bp - temp] - '0';

			//计
			if (sym - ap + temp < sym)
				a_flo[temp - 1] = input[sym - ap + temp] - '0';
			else
				a_flo[temp - 1] = 0;
			if (input_len - bp + temp < input_len)
				b_flo[temp - 1] = input[input_len - bp + temp] - '0';
			else
				b_flo[temp - 1] = 0;

			temp++;
		}
		printf("#%d:", now);
		if (input[sym] == '+')
			Add(a_int, a_flo, b_int, b_flo);
		else
		{	
			if (sym - ap < input_len - bp - sym)
			{
				printf("-");
				Minus(b_int, b_flo, a_int, a_flo);
			}
			else
				Minus(a_int, a_flo, b_int, b_flo);
		}

		for (int i = 0; i < 30; i++)
		{
			if (c_int[i] == 0 && flag == 0)
				continue;
			else if (c_int[i] != 0)
				flag = 1;
			printf("%d", c_int[i]);
		}
		for (int i = 29; i >= 0; i--)
		{
			if (c_flo[i] != 0)
			{
				point = i;
				break;
			}
		}
		//printf("%d",point);
		if (ap != 0 || bp != 0)
		{
			if (point < 0)
				break;
			printf(".");
			for (int i = 0; i < 30; i++)
			{
				if (i > point)
					break;
				printf("%d", c_flo[i]);
			}
		}
		printf("\n");
		now++;
	}
	return 0;
}