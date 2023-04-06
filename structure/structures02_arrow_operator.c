#include<stdio.h>

struct s_data
{
	int		x;
	int		y;
	int		*z;
};

// 構造体のポインタのメンバにポインタがあると*や.や()が増えてわかりにくくなる
// アロー演算子を用いることでプログラムも書きやすく、直感的に読めるようになる。

int	main(void)
{
	int				a;
	struct s_data	d;
	struct s_data	*pd;

	a = 3;
	pd = &d;
	pd->x = 1;
	pd->y = 2;
	pd->z = &a;

	printf("d.x = %d\n", pd->x);
	printf("d.y = %d\n", pd->y);
	printf("*(d.z) = %d\n", *(pd->z));

	return (0);
}
