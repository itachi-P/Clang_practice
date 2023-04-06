#include <stdio.h>

int	main(void)
{
	char	c = 'A';
	char	*cp = &c;

	printf("char c -> c: %c *c: (invalid) &c: %p\n", c, &c);
	printf("pointer *cp -> cp (cのアドレス): %p *cp (実体(=c)): %c &cp (ポインタ自体のアドレス): %p \n", cp, *cp, &cp);
	printf("The entity of the letter 'A' is a number-> c: %d *cp: %d 'a'(='A'+32): %d '0'(=0(=NULL)+'0'): %d\n", c, *cp, 'a', '0');
}