#include "create_nodes.h"

t_color	set_color(t_obj *obj, char *info)
{
	char	**nbrs;
	t_color	color;

	color = vec_init(COLOR, 0, 0, 0);
	nbrs = ft_split(info, ',');
	if (!nbrs)
		exit_system_fail();
	if (check_array_size(nbrs, 3) == TRUE)
	{
		if (ft_atod_check(nbrs[0]) == FALSE || ft_atod_check(nbrs[1]) == FALSE
			|| ft_atod_check(nbrs[2]) == FALSE)
			exit_wrong_infile(info);
		color.val[R] = ft_atod(nbrs[0]);
		color.val[G] = ft_atod(nbrs[1]);
		color.val[B] = ft_atod(nbrs[2]);
		check_color(&color);
	}
	else if (obj && check_array_size(nbrs, 1) == TRUE && nbrs[0][0] == 'M')
		obj->mirror = TRUE;
	else
		exit_msg("not a valid input file");
	return (color);
}

//calculate rotation matrixes from vector
void	calculate_rotations(t_transformation *matr, t_vector num)
{
	double	x;

	num = vec_normalize(VECTOR, num);
	if (num.val[Y] == 0.0 && num.val[Z] == 0)
		num.val[Y] = 0.001;
	x = acos(num.val[Z] / (sqrt(num.val[Y] * num.val[Y]
					+ num.val[Z] * num.val[Z])));
	matr->rotation_x = get_rotation_x_matrix(x);
	x = asin((-1) * num.val[X]);
	matr->rotation_y = get_rotation_y_matrix(x);
	matr->rotation_z = get_rotation_z_matrix(0);
}

void	create_rotations(t_transformation *matr, char *info)
{
	char		**nbrs;
	t_vector	num;

	num = vec_init(VECTOR, 0, 0, 0);
	nbrs = ft_split(info, ',');
	if (!nbrs)
		exit_system_fail();
	if (check_array_size(nbrs, 3) == FALSE)
		exit_wrong_infile(info);
	if (ft_atod_check(nbrs[0]) && ft_atod_check(nbrs[1])
		&& ft_atod_check(nbrs[2]))
	{
		num.val[X] = ft_atod(nbrs[0]);
		num.val[Y] = ft_atod(nbrs[1]);
		num.val[Z] = ft_atod(nbrs[2]);
	}
	else
		exit_wrong_infile(info);
	calculate_rotations(matr, num);
}

t_matrix	create_trans_matr(char *info)
{
	char	**nbrs;
	double	x;
	double	y;
	double	z;

	x = 0.0;
	y = 0.0;
	z = 0.0;
	nbrs = ft_split(info, ',');
	if (!nbrs)
		exit_system_fail();
	if (check_array_size(nbrs, 3) == FALSE)
		exit_wrong_infile(info);
	if (ft_atod_check(nbrs[0]) && ft_atod_check(nbrs[1])
		&& ft_atod_check(nbrs[2]))
	{
		x = ft_atod(nbrs[0]);
		y = ft_atod(nbrs[1]);
		z = ft_atod(nbrs[2]);
	}
	else
		exit_wrong_infile(info);
	return (get_translation_matrix(x, y, z));
}

t_vector	create_vec(char *info)
{
	t_vector	vec;
	char		**nbrs;

	vec = vec_init(VECTOR, 0, 0, 0);
	nbrs = ft_split(info, ',');
	if (!nbrs)
		exit_system_fail();
	if (check_array_size(nbrs, 3) == FALSE)
		exit_msg("not a valid input file");
	if (ft_atod_check(nbrs[0]) && ft_atod_check(nbrs[1])
		&& ft_atod_check(nbrs[2]))
	{
		vec.val[X] = ft_atod(nbrs[0]);
		vec.val[Y] = ft_atod(nbrs[1]);
		vec.val[Z] = ft_atod(nbrs[2]);
	}
	else
		exit_wrong_infile(info);
	ft_free_2d((void ***)&nbrs);
	return (vec);
}
