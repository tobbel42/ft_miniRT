#include "inter.h"

/*
//finds the intersection of a ray and a sphere
//return the smallest positive t(aka the nearest intersection
//from the camera(ray origin)), for ray = ray_origin + ray_direction * t
//negative values are returned, when no intersection is found
//working with a normalized sphere
//with radius = 1
*/
double	inter_sp(t_obj *sphere, t_ray ray)
{
	double	t;
	double	tab[3];
	double	dis;
	double	sqrt_dis;

	ray = ray_to_local(sphere, ray);
	tab[0] = vec_dot(ray.direction, ray.direction);
	tab[1] = 2 * vec_dot(ray.origin, ray.direction);
	tab[2] = vec_dot(ray.origin, ray.origin) - 1.0;
	dis = (tab[1] * tab[1]) - (4 * tab[0] * tab[2]);
	if (dis < 0)
		return (-1.0);
	sqrt_dis = sqrt(dis);
	t = ((-1 * tab[1]) - sqrt_dis) / (2 * tab[0]);
	if (t < 0)
		return (((-1 * tab[1]) + sqrt_dis) / (2 * tab[0]));
	return (t);
}
