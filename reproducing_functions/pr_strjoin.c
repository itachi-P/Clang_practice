#include <stdio.h>
#include <stdlib.h>

int	pr_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char	*pr_strcat(char *dest, char *src)
{
	char	*ret;

	ret = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (ret);
}

char	*pr_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*result;
	char	*p;

	if (size <= 0)
		return (NULL);
	len = 0;
	for (int i = 0; i < size; i++)
		len += pr_strlen(strs[i]);
	len += pr_strlen(sep) * (size - 1);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	p = result;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < pr_strlen(strs[i]); j++)
			*p++ = strs[i][j];
		if (i != size - 1)
			for (int j = 0; j < pr_strlen(sep); j++)
				*p++ = sep[j];
	}
	*p = '\0';
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
