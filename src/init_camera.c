#include	"mini_rt.h"

t_cam	set_cam_axis(t_cam cam)
{
	t_vector	right;
	t_vector	up;
	t_vector	dummy;

	if (cam.orient.direction.val[Z] == 1 || cam.orient.direction.val[Z] == -1)
	{
		dummy = vec_init(VECTOR, 0.0, 1.0, 0.0);
		right = vec_cross(VECTOR, dummy, cam.orient.direction);
		up = vec_cross(VECTOR, cam.orient.direction, right);
	}
	if (cam.orient.direction.val[X] == 1 || cam.orient.direction.val[X] == -1)
	{
		dummy = vec_init(VECTOR, 0.0, 1.0, 0.0);
		right = vec_cross(VECTOR, cam.orient.direction, dummy);
		up = vec_cross(VECTOR, right, cam.orient.direction);
	}
	if (cam.orient.direction.val[Y] == 1 || cam.orient.direction.val[Y] == -1)
	{
		right = vec_init(VECTOR, 1.0, 0.0, 0.0);
		up = vec_cross(VECTOR, right, cam.orient.direction);
	}
	return (trans_cam_axis(cam, up, right));
}

t_cam	trans_cam_axis(t_cam cam, t_vector up, t_vector right)
{
	cam.orient.direction = matrix_vec_multiplication(
			cam.transform, cam.orient.direction);
	cam.orient.origin = matrix_vec_multiplication(
			cam.transform, cam.orient.origin);
	cam.right = matrix_vec_multiplication(cam.transform, right);
	cam.up = matrix_vec_multiplication(cam.transform, up);
	return (cam);
}

t_cam	init_camera(int size_x, int size_y)
{
	t_cam		cam;
	double		l;
	t_vector	screen;

	cam = *get_data()->cams;
	cam = set_cam_axis(cam);
	cam.screen_ratio = (double)size_y / (double)size_x;
	l = tan(cam.fov / 2);
	screen = vec_add(POINT, cam.orient.origin, cam.orient.direction);
	cam.screen_origin = vec_add(
			VECTOR, screen, vec_scale(VECTOR, -1.0 * l, cam.right));
	cam.screen_origin = vec_add(
			VECTOR, cam.screen_origin,
			vec_scale(VECTOR, l * cam.screen_ratio, cam.up));
	cam.screen_step = 2 * l / ((double)size_x - 1);
	return (cam);
}
