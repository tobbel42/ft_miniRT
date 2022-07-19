#include "create_nodes.h"

t_obj	*create_plane_node(char *line)
{
	char	**infos;
	t_obj	*obj;

	infos = ft_split(line, ' ');
	obj = create_obj_node();
	obj->type = PLANE;
	if (!infos || !obj)
		return (NULL);
	if (check_array_size(infos, 4) == FALSE)
		exit_wrong_infile(line);
	obj->parmas.translation = create_trans_matr(infos[1]);
	create_rotations(&(obj->parmas), infos[2]);
	obj->parmas.scale = get_scale_matrix(1, 1, 1);
	obj->color = set_color(obj, infos[3]);
	ft_free_2d((void ***)&infos);
	check_plane_node(obj);
	return (obj);
}

void	create_ambient_node(char *line)
{
	char	**infos;
	t_data	*data;

	data = get_data();
	infos = ft_split(line, ' ');
	if (!infos)
		exit_system_fail();
	if (check_array_size(infos, 3) == FALSE)
		exit_wrong_infile(line);
	if (data->ambient.bright != 0 || infos[1] == FALSE)
		exit_wrong_infile(line);
	if (ft_atod_check(infos[1]) == FALSE)
		exit_wrong_infile(line);
	data->ambient.bright = ft_atod(infos[1]);
	check_range(data->ambient.bright, 0.0, 1.0);
	data->ambient.color = set_color(NULL, infos[2]);
	data->ambient.color
		= vec_scale(COLOR, 1.0 / 255.0, data->ambient.color);
	ft_free_2d((void ***)&infos);
	check_ambient_node();
}

void	create_circ_planes(t_obj *cyl)
{
	t_obj		*obj;
	t_matrix	help;

	obj = create_obj_node();
	obj->trans_to_global = cyl->trans_to_global;
	help = get_translation_matrix(0, 0, 1);
	obj->trans_to_global
		= matrix_multiplication(obj->trans_to_global, help);
	obj->trans_to_local
		= matrix_inverse(&(obj->trans_to_global), 4);
	obj->type = C_PLANE;
	obj->color = cyl->color;
	obj->mirror = cyl->mirror;
	cyl->next = obj;
	obj = create_obj_node();
	obj->trans_to_global = cyl->trans_to_global;
	help = get_translation_matrix(0, 0, -1);
	obj->trans_to_global
		= matrix_multiplication(obj->trans_to_global, help);
	obj->trans_to_local = matrix_inverse(&(obj->trans_to_global), 4);
	obj->color = cyl->color;
	obj->mirror = cyl->mirror;
	obj->type = C_PLANE;
	cyl->next->next = obj;
}

t_obj	*create_cylinder_node(char *line)
{
	char	**infos;
	t_obj	*obj;
	double	nbr;

	infos = ft_split(line, ' ');
	obj = create_obj_node();
	obj->type = CYLINDER;
	if (!infos || !obj)
		return (NULL);
	if (check_array_size(infos, 6) == FALSE)
		exit_msg("not a valid input file");
	obj->parmas.translation = create_trans_matr(infos[1]);
	create_rotations(&(obj->parmas), infos[2]);
	if (!(ft_atod_check(infos[3]) && ft_atod_check(infos[4])))
		exit_wrong_infile(line);
	nbr = ft_atod(infos[3]) / 2.0;
	obj->parmas.scale = get_scale_matrix(nbr, nbr, ft_atod(infos[4]) / 2.0);
	obj->color = set_color(obj, infos[5]);
	calc_transf_matr(obj);
	create_circ_planes(obj);
	ft_free_2d((void ***)&infos);
	check_cylinder_node(obj);
	return (obj);
}

t_obj	*create_obj_node(void)
{
	t_obj	*obj;

	obj = ft_calloc_protected(1, sizeof(t_obj));
	obj->next = NULL;
	return (obj);
}
