#include "mini_rt.h"

t_ray	ray_to_local(t_obj *obj, t_ray ray)
{
	t_ray	new_ray;

	new_ray.direction = matrix_vec_multiplication(
			obj->trans_to_local, ray.direction);
	new_ray.origin = matrix_vec_multiplication(
			obj->trans_to_local, ray.origin);
	new_ray.direction.val[W] = VECTOR;
	new_ray.origin.val[W] = POINT;
	return (new_ray);
}

t_ray	ray_to_global(t_obj *obj, t_ray ray)
{
	t_ray	new_ray;

	new_ray.direction = matrix_vec_multiplication(
			obj->trans_to_global, ray.direction);
	new_ray.origin = matrix_vec_multiplication(
			obj->trans_to_global, ray.origin);
	new_ray.direction.val[W] = VECTOR;
	new_ray.origin.val[W] = POINT;
	return (new_ray);
}

t_ray	get_intersection(t_ray ray, t_inter i_obj)
{
	t_ray	i;

	ray = ray_to_local(i_obj.obj, ray);
	i.origin = vec_add(POINT, ray.origin,
			vec_scale(POINT, i_obj.t, ray.direction));
	if (i_obj.obj->type == SPHERE)
		i = init_ray(i.origin, i.origin);
	if (i_obj.obj->type == PLANE || i_obj.obj->type == C_PLANE)
	{
		i.origin.val[W] = POINT;
		i.direction = vec_init(VECTOR, 0, 0, 1);
		if (vec_dot(i.direction, ray.direction) >= 0)
			i.direction = vec_scale(VECTOR, -1.0, i.direction);
	}
	if (i_obj.obj->type == CYLINDER)
	{
		i = init_ray(i.origin, i.origin);
		i.direction.val[Z] = 0.0;
	}
	i = ray_to_global(i_obj.obj, i);
	i.origin = vec_add(POINT, i.origin, vec_scale(POINT, 0.0001, i.direction));
	return (i);
}
