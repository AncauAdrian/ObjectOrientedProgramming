#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *data;
	int len;
} vector;

int gcd(int n1, int n2)
{
	while (n1 != n2)
	{
		if (n1 > n2)
			n1 -= n2;
		else
			n2 -= n1;
	}
	return n1;
}

int isPrime(int x)
{
	if (x == 1)
		return 0;
	if (x == 2)
		return 1;
	int i = 2;
	for (i; i*i <= x; i++)
		if (x % i == 0)
			return 0;

	return 1;
}

void naturals()
{
	int i = 3;
	int counter = 0;
	while (counter < 8)
	{
		int j = 2;
		for (j; j < i; j++)
		{
			if (gcd(i, j) == 1)
			{
				if (isPrime(j) == 0)
				{
					i++;
					continue;
				}
			}
		}

		printf("%i ", i);
		i++;
		counter++;
	}
}

void sequence()
{
	int a[100], n = 0;
	
	int i;
	scanf_s("%i\n", &i);
	while (i != -1)
	{
		a[n] = i;
		n++;
		scanf_s("%i\n", &i);
	}

	i = 1;
	int x = 0, len = 1, maxa = 0, maxb = 0, maxl = 0;
	while (i < n)
	{
		if (a[i] == a[i - 1])
			len++;
		else
		{
			if (len > maxl && len != 1)
			{
				maxa = x;
				maxb = i;
				maxl = len;
			}

			x = i;
			len = 1;
		}
		i++;
	}

	if (len > maxl && len != 1)
	{
		maxl = len;
		maxa = x;
		maxb = i - 1;
	}

	printf("The longest sequence:\n");
	i = maxa;
	for (i; i <= maxb; i++)
		printf("%i\n", a[i]);
}

vector readArray()
{
	int i, length;
	//scanf_s("Enter the length of the array: %d\n", &length);
	printf("Enter the length of the array: ");
	scanf_s("%d", &length);
	vector a;
	a.len = length;
	a.data = (int*)malloc(length * sizeof(int));
	for (i = 0; i < length; i++)
	{
		scanf_s("%d", &(a.data[i]));
	}
	return a;
}

void cont_sequence()
{
	vector a = readArray();

	int i = 1, len = 1, maxa = 0, maxb = 0, maxl = 1, x = 0;
	while (i < a.len)
	{
		if (a.data[i] >= a.data[i - 1] && isPrime(a.data[i] + a.data[i-1]))
			len++;
		else
		{
			if (len > maxl && len != 1)
			{
				maxa = x;
				maxb = i;
				maxl = len;
			}

			x = i;
			len = 1;
		}
		i++;
	}

	if (len > maxl && len != 1)
	{
		maxl = len;
		maxa = x;
		maxb = i - 1;
	}

	printf("The longest sequence:\n");
	i = maxa;
	for (i; i <= maxb; i++)
		printf("%i\n", a.data[i]);
}


int main()
{
	printf("1. Return the first 8 natural numbers with the condition\n2. Longest sequence\n0. Exit\n\n");

	while (1)
	{
		printf("\n>>");
		int c = getchar();

		if (c == '1')
			naturals();
		else if (c == '2')
			sequence();
		else if (c == '3')
			cont_sequence();
		else if (c == '0')
			break;
	}
	return 0;
}