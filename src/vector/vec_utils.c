#include "vector.h"

double	vec_dot(t_vector a, t_vector b)
{
	return (a.val[X] * b.val[X] + a.val[Y] * b.val[Y] + a.val[Z] * b.val[Z]);
}

t_vector	vec_cross(int type, t_vector a, t_vector b)
{
	return (vec_init(type, a.val[Y] * b.val[Z] - a.val[Z] * b.val[Y],
			a.val[Z] * b.val[X] - a.val[X] * b.val[Z],
			a.val[X] * b.val[Y] - a.val[Y] * b.val[X]));
}

t_vector	vec_init(int type, double x, double y, double z)
{
	t_vector	new_vec;

	new_vec.val[X] = x;
	new_vec.val[Y] = y;
	new_vec.val[Z] = z;
	new_vec.val[W] = type;
	return (new_vec);
}
