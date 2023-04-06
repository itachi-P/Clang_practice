#include <stdio.h>
#include <stdlib.h> // malloc()が含まれるライブラリ
#include <string.h> // memset()等が含まれるライブラリ

// 構造体の宣言
typedef struct strct_sample
{
	int		num;
	char	*str;
}			t_strct;

int	main(void)
{
	t_strct		*entity;

	// 動的メモリの確保
	entity = (t_strct *)malloc(sizeof(t_strct));

	// メンバの初期化
	entity->num = 001;
	// 構造体のメンバの文字列ポインタchar型用の領域を32個（文字数）分メモリ上に確保し、
	// 文字列ポインタにキャスト
	entity->str = (char *)malloc(sizeof(char) * 32);

	// メモリに文字列を代入
	sprintf(entity->str, "%s %s!", "Hello", "World");
	printf("%s\n", entity->str);

	// 別の文字列を配列で準備
	char	arr_str[] = "Good night United States of America!";

	// メモリの解放（内容を変更する前に必ず解放する癖をつけよう！）
	free(entity->str);
	// メモリサイズの変更
	entity->str = (char *)malloc(sizeof(arr_str));
	if (entity->str == NULL)
	{
		printf("memory error!");
		return -1;
	}
	// アドレスの先頭からarr_strのバイト数分だけNULL文字で置き換え
	memset(entity->str, '\0', sizeof(arr_str));

	printf("%s\n", entity->str);

	// メモリの解放
	free(entity->str);
	free(entity);

	printf("processing completion\n");

	return (0);
}