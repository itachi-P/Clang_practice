#include <stdio.h>

int	main(void)
{
	FILE	*fp = NULL;
	// FILE型のポインタ変数は宣言と同時にfopen()の返り値で初期化するのも一般的
	FILE	*fin = fopen("init.c", "r");

	printf("fp(initialized NULL): %p     fin: %p\n", fp, fin);
	return 0;
}