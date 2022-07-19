#ifndef CREATE_NODES_H
# define CREATE_NODES_H

# include "../mini_rt.h"
# include "check_nodes.h"
# include <math.h>

unsigned int	serial_color(t_color *color);
int				check_array_size(char **array, int desired);
t_vector		create_vec(char *info);
t_matrix		create_trans_matr(char *info);
void			create_rotations(t_transformation *matr, char *info);
void			calculate_rotations(t_transformation *matr, t_vector num);
t_color			set_color(t_obj *obj, char *str);

void			create_node_helper(char *line);
void			create_ambient_node(char *line);
void			create_camera_node(char *line);
void			create_light_node(char *line);
t_obj			*create_sphere_node(char *line);
t_obj			*create_plane_node(char *line);
t_obj			*create_cylinder_node(char *line);
void			norm_light(void);

int				ft_atod_check(const char *str);

#endif