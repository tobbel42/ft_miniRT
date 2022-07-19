#include "mini_rt.h"
#include "inter.h"

t_color	cast_reflection(t_ray ray, t_ray intersection,
	int depth, t_light *light)
{
	t_inter		inter;
	t_vector	n;
	t_vector	r_out;
	t_ray		reflect;

	n = vec_normalize(VECTOR, intersection.direction);
	r_out = vec_sub(VECTOR, ray.direction,
			vec_scale(VECTOR, 2.0 * vec_dot(ray.direction, n), n));
	reflect = init_ray(intersection.origin, r_out);
	inter = get_best_intersect(reflect);
	if (inter.obj && depth <= 5)
		return (cast_shadow(inter, reflect, light, depth + 1));
	else
		return (vec_init(COLOR, 0, 0, 0));
}

t_color	cast_shadow(t_inter	i_obj, t_ray ray, t_light *light, int depth)
{
	t_data		*data;
	t_ray		intersection;
	t_ray		to_light;
	t_inter		inter;
	double		len;

	data = get_data();
	intersection = get_intersection(ray, i_obj);
	(void)depth;
	if (i_obj.obj->mirror == TRUE)
		return (cast_reflection(ray, intersection, depth, light));
	to_light = init_ray(intersection.origin,
			vec_sub(VECTOR, light->translation, intersection.origin));
	len = vec_dot(to_light.direction, to_light.direction);
	len = sqrt(len);
	to_light.direction = vec_normalize(VECTOR, to_light.direction);
	inter = get_best_intersect(to_light);
	if (inter.obj != NULL && inter.t < len)
		return (vec_init(VECTOR, 0, 0, 0));
	return (vec_add(VECTOR, get_diffuse_light(to_light, intersection,
				i_obj, light), get_specular_light(to_light, intersection,
				ray, light)));
}

t_color	get_color(t_cam cam, int x, int y)
{
	t_inter	inter;
	t_color	color;
	t_ray	ray;
	t_light	*light;

	ray = render_ray(cam, x, y);
	inter = get_best_intersect(ray);
	if (inter.obj)
	{
		light = get_data()->lights;
		color = vec_init(COLOR, 0, 0, 0);
		while (light)
		{
			color = vec_add(COLOR, color, cast_shadow(inter, ray, light, 1));
			light = light->next;
		}
		if (inter.obj->mirror != TRUE)
			color = vec_add(COLOR, color, get_ambient_light(inter));
		return (color);
	}
	else
		color = vec_init(VECTOR, 0, 0, 0);
	return (color);
}
