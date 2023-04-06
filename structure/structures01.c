#include<stdio.h>

struct s_data
{
	int		x;
	int		y;
	int		*z;
};

int	main(void)
{
	int				a;	
	struct s_data	d;
	struct s_data	*pd;

	a = 3;
	d.x = 1;
	d.y = 2;
	d.z = &a;

	pd = &d;

	printf("d.x = %d\n", (*pd).x);
	printf("d.y = %d\n", (*pd).y);
	printf("*(d.z) = %d\n", *((*pd).z));

	return (0);
}
