#include <stdio.h>
#include <stdlib.h>

#define N 4

void	printQueen(int queen[N])
{
	int	i;

	printf("%d queen : ", N);
	for (i = 0; i < N; i++)
	{
		printf("%d ", queen[i]);
	}
	printf("\n");
}

int	check(int queen[N])
{
	int i, j;
	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (queen[i] == queen[j] || abs(queen[i] - queen[j]) == j - i)
				return (0);
		}
	}
	return (1);
}

void	setQueen(int queen[], int i)
{
	int	j;

	if (i == N)
	{
		if (check(queen))
			printQueen(queen);
		return ;
	}
	for (j = 0; j < N; j++)
	{
		queen[i] = j;
		setQueen(queen, i + 1);
	}
}

int	main(void)
{
	int queen[N];
	setQueen(queen, 0);
}