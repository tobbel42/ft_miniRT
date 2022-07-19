#include "mini_rt.h"
#include "check_nodes.h"

void	check_camera_node(t_cam *cam)
{
	check_vec_normal(cam->orient.direction);
	check_range(cam->fov, 0.0, 180.0);
}

void	check_light_node(t_light *light)
{
	check_range(light->bright, 0.0, 1.0);
}

void	check_sphere_node(t_obj *node)
{
	(void)node;
}

void	check_plane_node(t_obj *node)
{
	(void)node;
}

void	check_cylinder_node(t_obj *node)
{
	(void)node;
}
