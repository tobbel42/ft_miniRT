#include "create_nodes.h"
//never checking single values with ft_atod_check before assigning them
void	add_camera_node(t_cam *cam)
{
	t_data	*data;
	t_cam	*node;

	data = get_data();
	check_camera_node(cam);
	node = data->cams;
	if (!node)
	{
		data->cams = cam;
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = cam;
}

void	create_camera_node(char *line)
{
	char	**infos;
	t_cam	*cam;

	infos = ft_split(line, ' ');
	cam = ft_calloc(1, sizeof(t_cam));
	if (!infos)
		exit_system_fail();
	if (check_array_size(infos, 4) == FALSE)
		exit_wrong_infile(line);
	cam->orient.origin = create_vec(infos[1]);
	cam->orient.direction = create_vec(infos[2]);
	if (ft_atod_check(infos[3]) == FALSE)
		exit_wrong_infile(line);
	cam->fov = ft_atod(infos[3]);
	check_range(cam->fov, 0.0, 180.0);
	cam->fov = cam->fov / 180 * M_PI;
	ft_free_2d((void ***)&infos);
	add_camera_node(cam);
}

void	add_light_node(t_light *light)
{
	t_data	*data;
	t_light	*node;

	data = get_data();
	check_light_node(light);
	node = data->lights;
	if (!node)
	{
		data->lights = light;
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = light;
}

void	create_light_node(char *line)
{
	char	**infos;
	t_light	*light;

	infos = ft_split(line, ' ');
	light = ft_calloc_protected(1, sizeof(t_light));
	if (!infos)
		exit_system_fail();
	if (check_array_size(infos, 4) == FALSE)
		exit_wrong_infile(line);
	light->translation = create_vec(infos[1]);
	if (ft_atod_check(infos[2]) == FALSE)
		exit_wrong_infile(line);
	light->bright = ft_atod(infos[2]);
	check_range(light->bright, 0.0, 1.0);
	light->color = set_color(NULL, infos[3]);
	ft_free_2d((void ***)&infos);
	light->color = vec_scale(COLOR, (1.0 / 255.0), light->color);
	add_light_node(light);
}

t_obj	*create_sphere_node(char *line)
{
	char	**infos;
	t_obj	*obj;
	double	nbr;

	infos = ft_split(line, ' ');
	obj = create_obj_node();
	obj->type = SPHERE;
	if (!infos || !obj)
		return (NULL);
	if (check_array_size(infos, 4) == FALSE)
		exit_wrong_infile(line);
	obj->parmas.translation = create_trans_matr(infos[1]);
	if (ft_atod_check(infos[2]) == FALSE)
		exit_wrong_infile(line);
	nbr = ft_atod(infos[2]) / 2.0;
	obj->parmas.scale = get_scale_matrix(nbr, nbr, nbr);
	obj->color = set_color(obj, infos[3]);
	obj->parmas.rotation_x = get_rotation_x_matrix(0);
	obj->parmas.rotation_y = get_rotation_y_matrix(0);
	obj->parmas.rotation_z = get_rotation_z_matrix(0);
	ft_free_2d((void ***)&infos);
	check_sphere_node(obj);
	return (obj);
}
