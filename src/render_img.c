#include "mini_rt.h"
#include "inter.h"

t_inter	get_best_intersect(t_ray ray)
{
	t_obj	*node;
	t_inter	inter;
	double	t;

	inter.obj = NULL;
	node = get_data()->objs;
	while (node)
	{
		if (node->type == SPHERE)
			t = inter_sp(node, ray);
		else if (node->type == PLANE)
			t = inter_pl(node, ray);
		else if (node->type == CYLINDER)
			t = inter_cy(node, ray);
		else if (node->type == C_PLANE)
			t = inter_c_pl(node, ray);
		if (t > 0 && (!(inter.obj) || t < inter.t))
		{
			inter.t = t;
			inter.obj = node;
		}
		node = node->next;
	}
	return (inter);
}

t_ray	init_ray(t_vector origin, t_vector direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.origin.val[W] = POINT;
	ray.direction = direction;
	ray.direction.val[W] = VECTOR;
	return (ray);
}

t_ray	render_ray(t_cam cam, int x, int y)
{
	t_vector	point;
	t_vector	normal;
	t_ray		ray;

	point = vec_add(POINT, cam.screen_origin,
			vec_scale(POINT,
				(double)x * cam.screen_step, cam.right));
	point = vec_add(POINT, point,
			vec_scale(POINT,
				(double)y * -1.0 * cam.screen_step, cam.up));
	normal = vec_sub(VECTOR, point, cam.orient.origin);
	normal = vec_normalize(VECTOR, normal);
	ray = init_ray(cam.orient.origin, normal);
	return (ray);
}

/*
//iterate over every pixel of the image
//for each pixel a ray is generated, which is passed to the get color function
//which calculates the color of the pixel
*/
void	render_img(t_cam cam)
{
	void	*dst;
	t_color	color;
	int		x;
	int		y;

	dst = get_data()->mlx_img_ptr;
	y = 0;
	while (y < IMG_Y)
	{
		x = 0;
		while (x < IMG_X)
		{
			color = get_color(cam, x, y);
			*(unsigned int *)dst = serial_color(&color);
			dst += get_data()->mlx_bpp / 8;
			x++;
		}
		y++;
	}
}
