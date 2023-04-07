#include<stdio.h>
#include<stdlib.h>

// 構造体の宣言
typedef struct strct_sample
{
	int		num;
	char	*str;
}	t_strct;

int	main(void)
{
	// ポインタ型の変数を生成
	t_strct	*entity;
	// 動的メモリの確保
	entity = (t_strct *)malloc(sizeof(t_strct));
	// メンバの初期化
	entity->num = 0;
	entity->str = (char *)malloc(sizeof(char) * 32);
	// メモリに文字列を代入
	sprintf(entity->str, "%s %s!", "Hello", "World");
	printf("%s\n", entity->str);
	// メモリの解放
	free(entity->str);
	free(entity);
	return (0);
}
