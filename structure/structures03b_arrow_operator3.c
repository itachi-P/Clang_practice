#include <stdio.h>

struct			s_memb
{
	int			m;
};

struct			s_data
{
	struct s_memb	x;
	struct s_memb	*y;
};

// 構造体のメンバに他の構造体が含まれる場合
int	main(void)
{
	struct s_data		d;
	struct s_data		*pd;

	pd = &d;

	d.x.m = 1;
	d.y->m = 2;

	pd->x.m = 3;
	// pd->y->m のようにアロー演算子を複数回連続で使用することも可能
	pd->y->m = 4;

	return (0);
}
