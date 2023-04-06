#include <stdio.h>

int	main(void)
{
	int	a = 1;
	int	*ap = &a;

	printf("int a -> a: %d *a: -(invalid) &a: %p\n", a, &a);
	printf("pointer *ap -> ap (aのアドレス): %p *ap (ポインタapが持つ実体(=a)): %d &ap (ポインタap自体のアドレス): %p \n", ap, *ap, &ap);
	// return (0); // 省略しても通るが書いた方がいい
}