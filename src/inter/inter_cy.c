#include "inter.h"

double	inter_c_pl(t_obj *plane, t_ray ray)
{
	double		t;
	double		div;
	t_vector	point;
	t_vector	normal;

	ray = ray_to_local(plane, ray);
	normal = vec_init(VECTOR, 0.0, 0.0, 1.0);
	div = vec_dot(normal, ray.direction);
	if (div == 0)
		return (-1.0);
	else
		t = -1.0 * vec_dot(ray.origin, normal) / div;
	point = vec_add(POINT, ray.origin, vec_scale(POINT, t, ray.direction));
	if ((point.val[X] * point.val[X] + point.val[Y] * point.val[Y]) <= 1)
		return (t);
	return (-1.0);
}

static double	inter_cy_helper(t_ray ray, double tab[3], double dis_sqrt)
{
	double	z_pos[2];
	double	t[2];

	t[0] = ((-1 * tab[1]) + dis_sqrt) / (2 * tab[0]);
	t[1] = ((-1 * tab[1]) - dis_sqrt) / (2 * tab[0]);
	z_pos[0] = fabs(ray.origin.val[Z] + ray.direction.val[Z] * t[0]);
	z_pos[1] = fabs(ray.origin.val[Z] + ray.direction.val[Z] * t[1]);
	if (z_pos[0] <= 1 && z_pos[1] <= 1)
	{
		if (t[0] < t[1])
			return (t[0]);
		return (t[1]);
	}
	if (z_pos[0] <= 1)
		return (t[0]);
	if (z_pos[1] <= 1)
		return (t[1]);
	return (-1.0);
}

double	inter_cy(t_obj *cyl, t_ray ray)
{
	double	tab[3];
	double	dis;
	double	dis_sqrt;

	ray = ray_to_local(cyl, ray);
	tab[0] = ray.direction.val[X] * ray.direction.val[X]
		+ ray.direction.val[Y] * ray.direction.val[Y];
	tab[1] = 2 * (ray.origin.val[X] * ray.direction.val[X]
			+ ray.origin.val[Y] * ray.direction.val[Y]);
	tab[2] = ray.origin.val[X] * ray.origin.val[X]
		+ ray.origin.val[Y] * ray.origin.val[Y] - 1;
	dis = (tab[1] * tab[1]) - (4 * tab[0] * tab[2]);
	if (dis < 0)
		return (-1.0);
	dis_sqrt = sqrt(dis);
	return (inter_cy_helper(ray, tab, dis_sqrt));
}
