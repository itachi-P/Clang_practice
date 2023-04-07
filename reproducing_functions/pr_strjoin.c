#include <stdlib.h>
#include <stdio.h>

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
	while (*dest)
		++dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*pr_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*result;
	char	*p;

	len = 0;
	while (size--)
		len += pr_strlen(*strs++);
	len += (pr_strlen(sep) * (size + 1));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	p = result;
	while (*strs)
	{
		pr_strcat(p, *strs++);
		if (*strs)
			pr_strcat(p, sep);
	}
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
