#include <stdio.h>
#include <stdlib.h>

/* 文字列の長さを返す関数 */
int	pr_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/* 文字列を結合する関数 */
char	*pr_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*result;
	int		p;
	int		j;

	/* 結合後の文字列の長さを計算 */
	len = 0;
	for (int i = 0; i < size; i++)
		len += pr_strlen(strs[i]) + pr_strlen(sep);
	len -= pr_strlen(sep);
	/* 結合後の文字列を格納するためのメモリを確保 */
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	/* 結合後の文字列を生成 */
	p = 0;
	for (int i = 0; i < size; i++)
	{
		j = 0;
		while (strs[i][j])
			result[p++] = strs[i][j++];
		j = 0;
		while (sep[j] && i != size - 1)
			result[p++] = sep[j++];
	}
	result[p] = '\0';
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
