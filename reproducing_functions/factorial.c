#include <stdio.h>
#include <stdlib.h>

// 再帰関数でnの階乗を計算
int	factorial(int n)
{
	if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}

// malloc関数とポインタ渡しの使用例
// int型の配列を作成し、その合計を計算
int	sum_array(int *arr, int size)
{
	int	sum;

	sum = 0;
	if (arr == NULL)
	{
		printf("Error: array is not allocated.\n");
		return (0);
	}
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return (sum);
}

int	main(void)
{
	int	n;
	int	size;
	int	*arr;

	// 階乗関数のテスト
	n = 5;
	printf("%d!(%dの階乗) = %d\n", n, n, factorial(n));
	// 配列の合計を計算する関数のテスト
	size = 5;
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
	{
		printf("Error: failed to allocate memory.\n");
		return (1);
	}
	for (int i = 0; i < size; i++)
		arr[i] = i + 1;
	printf("sum of array(int型配列内の要素の合計) = %d\n", sum_array(arr, size));
	free(arr); // mallocで確保したメモリを解放する。メモリ確保→解放は必ずセットで行う。
	return (0);
}
