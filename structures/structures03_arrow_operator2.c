#include <stdio.h>

struct	s_data
{
	int	x;
	int	y;
};

/* メンバにアクセスする際にアロー演算子(->)を使うか、(.)かの使い分け
演算子の左側の変数がポインタである場合は「->」を用い、
演算子の左側の変数がポインタでない（構造体データの実体である）場合は「.」を用いれば良い
*/

int	main(void)
{
	struct s_data	d;
	struct s_data	*pd;

	pd = &d;

	// d はポインタではない
	d.x = 1;
	d.y = 2;

	// pd はポインタ
	pd->x = 3;
	pd->y = 4;

	// *pd はポインタでない
	(*pd).x = 5;
	(*pd).y = 6;

	return (0);
}