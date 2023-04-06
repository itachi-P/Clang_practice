#include <stdio.h>

int	main(void)
{
	/*
	ポインタを宣言だけして初期化せずに使う人も実際多いが、それは経験によって不要と判断しているから。
	特に初心者のうちは毎回必ず最初にNULLまたは値の代入などで初期化する癖をつけておいた方が無難。
	ポインタにデタラメなアドレスが入ることによる想定外のエラーが発生しやすい。
	或いはエラーにもならず、期待と違う動作をし続けた場合は最悪で、その場合原因を特定するのも非常に困難。
	*/
	const char	*s1 = NULL;
	const char	*s2 = "Hello, World!";

	printf("*s1(initialized NULL): %s     *s2: %s\n", s1, s2);
	printf("s2(文字列\"Hello, World!\"の最初のアドレスを指す): %p *s2(実体=最初の1文字'H'):%c &s2(ポインタ自身のアドレス)%p\n", s2, *s2, &s2);
	// printf("*s1(initialized NULL): %c\n", *s1); // これをやるとセグフォが発生する(NULL参照)
	return 0;
}