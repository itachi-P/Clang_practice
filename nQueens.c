#include <stdio.h>
#define N 8

int		board[N][N] = {0}; // 8x8の盤面
int		solutions = 0;     // 解の数

void	print_solution(void)
{
	// 盤面を表示する
	printf("Solution %d:\n", solutions + 1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 1)
			{
				printf("Q ");
			}
			else
			{
				printf(". ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

int	can_place(int row, int col)
{
	// クイーンを配置できるかどうかを判断する
	for (int i = 0; i < row; i++)
	{
		if (board[i][col] == 1)
		{
			return (0); // 同じ列にある
		}
		if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 1)
		{
			return (0); // 左上の対角線にある
		}
		if (row - i >= 0 && col + i < N && board[row - i][col + i] == 1)
		{
			return (0); // 右上の対角線にある
		}
	}
	return (1);
}

void	solve(int row)
{
	// 行を基準にクイーンを配置する
	if (row == N)
	{ // 全ての行に配置された場合
		solutions++;
		print_solution();
		return ;
	}
	for (int col = 0; col < N; col++)
	{ // 各列を試す
		if (can_place(row, col))
		{ // クイーンを配置できる場合
			board[row][col] = 1;
			solve(row + 1);
			board[row][col] = 0; // 解が見つからなかった場合、この位置から始まる他の解を探すために戻す
		}
	}
}

int	main(void)
{
	solve(0);
	printf("Found %d solutions.\n", solutions);
	return (0);
}
