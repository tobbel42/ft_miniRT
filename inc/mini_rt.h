#ifndef MINI_RT_H
# define MINI_RT_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include "exit.h"
# include "matrix.h"
# include "vector.h"
# include "object.h"

//size of the output image
# define IMG_X 1920
# define IMG_Y 1080

typedef struct s_data
{
	t_obj		*objs;
	t_cam		*cams;
	t_light		*lights;
	t_ambient	ambient;
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_img;
	void		*mlx_img_ptr;
	int			mlx_ll;
	int			mlx_bpp;
	int			mlx_endian;
}	t_data;

typedef struct s_inter
{
	t_obj		*obj;
	long double	t;
}	t_inter;

t_data			*get_data(void);
void			input_parse(int argc, char **argv);

unsigned int	hit_stuff(int y, int x);

void			create_new_image(void);

t_cam			init_camera(int size_x, int size_y);
t_cam			set_cam_axis(t_cam cam);
t_cam			trans_cam_axis(t_cam cam, t_vector up, t_vector right);
void			init_img(int size_x, int size_y);
void			iter_over_img(t_cam cam);

t_color			get_color(t_cam cam, int x, int y);
t_ray			init_ray(t_vector origin, t_vector direction);
t_ray			ray_to_global(t_obj *obj, t_ray ray);
t_ray			ray_to_local(t_obj *obj, t_ray ray);
t_ray			render_ray(t_cam cam, int x, int y);
void			render_img(t_cam cam);

t_inter			get_best_intersect(t_ray ray);
t_color			get_diffuse_light(t_ray to_light, t_ray intersection,
					t_inter i_obj, t_light *light);
t_color			get_specular_light(t_ray to_light, t_ray intersection,
					t_ray ray, t_light *light);
t_color			cast_shadow(t_inter	i_obj, t_ray ray, t_light *light,
					int depth);
t_color			get_ambient_light(t_inter intercept);
unsigned int	serial_color(t_vector *color);
t_ray			get_intersection(t_ray ray, t_inter i_obj);
t_color			cast_reflection(t_ray ray, t_ray intersection,
					int depth, t_light *light);

#endif