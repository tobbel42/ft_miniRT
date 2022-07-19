#include "mini_rt.h"

t_color	get_specular_light(t_ray to_light, t_ray intersection,
		t_ray ray, t_light *light)
{
	t_vector	r_in;
	t_vector	n;
	double		lum;
	t_color		color;

	n = vec_normalize(VECTOR, intersection.direction);
	r_in = vec_scale(VECTOR, -1.0, to_light.direction);
	lum = -1 * vec_dot(vec_sub(VECTOR, r_in,
				vec_scale(VECTOR, 2.0 * vec_dot(r_in, n), n)), ray.direction);
	color = vec_init(COLOR, 0.0, 0.0, 0.0);
	if (lum > 0.001)
	{
		lum = (202) / (2 * M_PI) * pow(lum, 202);
		color.val[R] = light->color.val[R] * lum;
		color.val[G] = light->color.val[G] * lum;
		color.val[B] = light->color.val[B] * lum;
	}
	return (color);
}

t_color	get_diffuse_light(t_ray to_light, t_ray intersection,
		t_inter i_obj, t_light *light)
{
	double	lum;
	t_color	color;

	lum = vec_dot(to_light.direction,
			vec_normalize(VECTOR, intersection.direction))
		* light->bright;
	if (lum <= 0.0)
		color = vec_init(VECTOR, 0, 0, 0);
	else
	{
		color = vec_init(VECTOR,
				i_obj.obj->color.val[R] * light->color.val[R],
				i_obj.obj->color.val[G] * light->color.val[G],
				i_obj.obj->color.val[B] * light->color.val[B]);
		color = vec_scale(COLOR, lum, color);
	}
	return (color);
}

t_color	get_ambient_light(t_inter intercept)
{
	t_color	color;
	t_data	*data;

	data = get_data();
	color.val[R] = intercept.obj->color.val[R] * data->ambient.color.val[R];
	color.val[G] = intercept.obj->color.val[G] * data->ambient.color.val[G];
	color.val[B] = intercept.obj->color.val[B] * data->ambient.color.val[B];
	color = vec_scale(COLOR, data->ambient.bright, color);
	return (color);
}
