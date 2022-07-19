#include "vector.h"

t_vector	vec_sub(int type, t_vector a, t_vector b)
{
	return (vec_init(type, a.val[X] - b.val[X],
			a.val[Y] - b.val[Y], a.val[Z] - b.val[Z]));
}

t_vector	vec_add(int type, t_vector a, t_vector b)
{
	return (vec_init(type, a.val[X] + b.val[X],
			a.val[Y] + b.val[Y], a.val[Z] + b.val[Z]));
}

t_vector	vec_scale(int type, double t, t_vector a)
{
	return (vec_init(type, a.val[X] * t, a.val[Y] * t, a.val[Z] * t));
}

t_vector	vec_normalize(int type, t_vector a)
{
	double	len;

	len = sqrt(vec_dot(a, a));
	return (vec_scale(type, 1 / len, a));
}
