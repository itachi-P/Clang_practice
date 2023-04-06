#include <stdio.h>
#include <stdlib.h> 
#include <string.h> // memcmp()等が含まれるライブラリ

// memcmp: 指定バイト数のメモリ領域を比較する
// 戻り値が0の場合は比較の結果オブジェクトは一致と判定

int	main(void)
{
	// 変数の用意
	char	*str1;
	char	*str2;

	// 動的メモリの確保
	str1 = (char *)malloc(sizeof(char) * 32);
	str2 = (char *)malloc(sizeof(char) * 32);

	// メモリの初期化
	memset(str1, '\0', sizeof(char) * 32);
	memset(str2, '\0', sizeof(char)*32);

	// 文字列を入れる
	strcpy(str1, "ABCDE!");
	strcpy(str2, "ABCDEF!");
	// 比較する
	if (memcmp(str1, str2, (sizeof(char) * 32)) == 0)
	{
		printf("同一の内容です。");
	} else {
		printf("同一の内容ではありません！");
	}
	

	// メモリの解放処理
	free(str1);
	free(str2);

	return (0);
}
