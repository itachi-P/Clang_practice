#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset(), memcpy等が含まれるライブラリ

// 構造体の宣言
typedef struct // typedef宣言の識別子は省略可能だが、normには怒られる
{
	int		num;
	char	*str;
} strct; // t_で始まらないとnormには怒られる

int	main(void)
{
	strct	*entity;
	strct	*copy_entity;

	// 動的メモリの確保
	entity = (strct *)malloc(sizeof(strct));
	// メンバの初期化
	entity->num = 001;
	entity->str = (char *)malloc(sizeof(char) * 32);
	// メモリに文字列を代入
	sprintf(entity->str, "%s %s!", "Hello", "World");
	printf("%s\n", entity->str);
	// 構造体の実体のコピー
	copy_entity = (strct *)malloc(sizeof(strct));
	memcpy(copy_entity, entity, sizeof(strct)); // メンバのポインタは浅いコピー
	// 浅いコピーのため、コピー元の値が変わるとコピー先の値も変わる
	strcpy(entity->str, "Hello, Japonica!");
	printf("%s, %s\n", entity->str, copy_entity->str);
	// 深いコピーにする為には、メンバ個別でコピーが必要
	copy_entity->str = (char *)malloc(sizeof(char) * 32);
	strcpy(copy_entity->str, entity->str);
	// 深いコピーのため、コピー元の値が変わってもコピー先の値は変わらない
	strcpy(entity->str, "Hello, Portugal?");
	printf("%s %s\n", entity->str, copy_entity->str);
	// メモリの解放（内容を変更する前に必ず解放する癖をつけよう！）
	free(copy_entity->str);
	free(copy_entity);
	free(entity->str);
	free(entity);
	printf("processing completion\n");
	return (0);
}
