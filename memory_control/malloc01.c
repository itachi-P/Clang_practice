#include <stdio.h>
#include <stdlib.h> // mallocが含まれるライブラリ

/*
malloc(sizeof(構造体や配列など))
引数で指定するバイト数分のメモリが確保され、確保したメモリ領域へのポインタを返す。
確保したメモリはfree関数で必ず解放する必要がある。
*/

// 構造体の宣言
typedef struct persons
{
	int		id;
	char	*name;
	char	*address;
}	t_person1;

int	main(void)
{
	t_person1	*entity;	// ポインタ型の変数を生成

	// 動的メモリの確保
	entity = (t_person1 *)malloc(sizeof(t_person1));

	// メンバの初期化
	entity->id = 001;
	entity->name = (char *)malloc(sizeof(char) * 32);
	entity->address = (char *)malloc(sizeof(char) * 64);

	// メモリに文字列を代入
	sprintf(entity->name, "I am %s %s. Yoropiku!", "Itachi-P", "Shinohara");
	printf("%s\n", entity->name);

	// メモリの解放
	free(entity->name);
	free(entity);

	return (0);
}