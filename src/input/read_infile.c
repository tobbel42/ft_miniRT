#include "parse.h"

void	add_obj_node(t_obj *new_node)
{
	t_data	*data;
	t_obj	*node;

	data = get_data();
	if ((data->objs) == NULL)
	{
		data->objs = new_node;
		return ;
	}
	node = data->objs;
	while (node->next)
		node = node->next;
	node->next = new_node;
}

void	create_node(char *line)
{
	if (line[0] == '\n')
		return ;
	else if (line[0] == 'A' || line[0] == 'C'
		|| line[0] == 'L' || line[0] == 'l')
	{
		if (ft_strncmp(line, "A ", 2) == 0)
			create_ambient_node(line);
		else if (ft_strncmp(line, "C ", 2) == 0)
			create_camera_node(line);
		else if ((ft_strncmp(line, "l ", 2) == 0)
			|| ft_strncmp(line, "L ", 2) == 0)
			create_light_node(line);
		return ;
	}
	create_node_helper(line);
}

void	create_node_helper(char *line)
{
	t_obj	*new_node;

	new_node = NULL;
	if (ft_strncmp(line, "sp ", 3) == 0)
		new_node = create_sphere_node(line);
	else if (ft_strncmp(line, "pl ", 3) == 0)
		new_node = create_plane_node(line);
	else if (ft_strncmp(line, "cy ", 3) == 0)
		new_node = create_cylinder_node(line);
	else
		exit_wrong_infile(line);
	if (!new_node)
		exit_msg("sorry, something went wrong");
	calc_transf_matr(new_node);
	add_obj_node(new_node);
}

void	read_infile(void)
{
	t_parse	*parse_data;
	t_data	*data;
	char	*line;

	parse_data = get_parse_data();
	data = get_data();
	line = get_next_line(parse_data->in_fd);
	while (line != NULL)
	{
		create_node(line);
		free(line);
		line = get_next_line(parse_data->in_fd);
	}
	norm_light();
	if (!data->cams)
		exit_wrong_infile(NULL);
}

void	norm_light(void)
{
	t_data	*data;
	t_light	*node;
	double	lum_sum;

	data = get_data();
	node = data->lights;
	lum_sum = 0.0;
	while (node)
	{
		lum_sum += node->bright;
		node = node->next;
	}
	lum_sum += data->ambient.bright;
	node = data->lights;
	while (node)
	{
		node->bright /= lum_sum;
		node = node->next;
	}
	data->ambient.bright /= lum_sum;
}
