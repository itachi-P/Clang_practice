#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>
#include <string.h>

/*
** 文字列の長さを返す関数
*/
static int	pr_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/*
** 複数の文字列を結合する関数
** size: 結合する文字列の個数
** strs: 結合する文字列の配列
** sep: 各文字列を区切るための区切り文字列
** return: 結合された文字列へのポインタ。メモリ確保に失敗した場合はNULLを返す
*/
char	*pr_strjoin(int size, char **strs, char *sep)
{
	char	*result; // 結合された文字列
	int		result_len; // 結合された文字列の長さ
	int		sep_len; // 区切り文字列の長さ

	if (size <= 0)
		return (NULL);

	// 結合後の文字列の長さを求める
	result_len = 0;
	sep_len = pr_strlen(sep);
	for (int i = 0; i < size; i++)
		result_len += pr_strlen(strs[i]) + (i < size - 1 ? sep_len : 0);

	// メモリを確保して、文字列を結合する
	result = (char *)malloc(result_len + 1);
	if (!result)
		return (NULL);

	int	idx = 0; // resultの現在のインデックス
	for (int i = 0; i < size; i++)
	{
		// 区切り文字列をresultに追加
		if (i != 0)
			for (int j = 0; j < sep_len; j++)
				result[idx++] = sep[j];

		// 文字列をresultに追加
		for (int j = 0; j < pr_strlen(strs[i]); j++)
			result[idx++] = strs[i][j];
	}
	result[result_len] = '\0';

	return (result);
}

int	main(void)
{
	char	*strs[] = {"fugafuga", "hogehoge", "Fizz", "Buzz", "hoehoe"};
	char	*sep;
	char	*joined;

	sep = "__+__";
	joined = pr_strjoin(5, strs, sep);
	printf("%s\n", joined);
	free(joined);
	return (0);
}
