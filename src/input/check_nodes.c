#include "mini_rt.h"

int	check_array_size(char **array, int desired)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i == desired);
}

void	check_range(double value, double lim_low, double lim_high)
{
	if (value < lim_low || value > lim_high)
	{
		exit_wrong_infile(NULL);
	}
}

void	check_color(t_color *color)
{
	check_range(color->val[R], 0.0, 255.0);
	check_range(color->val[G], 0.0, 255.0);
	check_range(color->val[B], 0.0, 255.0);
}

void	check_vec_normal(t_vector vec)
{
	double	len;

	len = sqrt(pow(vec.val[X], 2.0) + pow(vec.val[Y], 2.0)
			+ pow(vec.val[Z], 2.0));
	check_range(len, 1.0, 1.0);
}

void	check_ambient_node(void)
{
	t_data	*data;

	data = get_data();
	check_range(data->ambient.bright, 0.0, 1.0);
}
