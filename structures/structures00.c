#include<stdio.h>

struct s_data
{
	int		x;
	int		y;
};

int	main(void)
{
	struct s_data	d;

	d.x = 1;
	d.y = 2;

	printf("d.x = %d\n", d.x);
	printf("d.y = %d\n", d.y);

	return (0);
}
