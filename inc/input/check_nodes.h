#ifndef CHECK_NODES_H
# define CHECK_NODES_H

# include "../mini_rt.h"

void	check_range(double value, double lim_low, double lim_high);
void	check_color(t_color *color);
void	check_vec_normal(t_vector vec);

void	check_ambient_node(void);
void	check_camera_node(t_cam *cam);
void	check_light_node(t_light *light);
void	check_sphere_node(t_obj *node);
void	check_plane_node(t_obj *node);
void	check_cylinder_node(t_obj *node);

#endif