#ifndef OBJECT_H
# define OBJECT_H

# include "matrix.h"
# include "vector.h"

enum e_obj
{
	NIL,
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	C_PLANE
};

typedef t_vector	t_color;

typedef struct s_transformation
{
	t_matrix	translation;
	t_matrix	rotation_x;
	t_matrix	rotation_y;
	t_matrix	rotation_z;
	t_matrix	scale;
}	t_transformation;

typedef struct s_obj
{
	int					type;
	t_matrix			trans_to_local;
	t_matrix			trans_to_global;
	t_transformation	parmas;
	t_color				color;
	int					mirror;
	struct s_obj		*next;
}	t_obj;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

typedef struct s_cam
{
	t_ray			orient;
	t_matrix		transform;
	double			fov;

	t_vector		right;
	t_vector		up;

	double			screen_step;
	double			screen_ratio;
	t_vector		screen_origin;

	struct s_cam	*next;
}	t_cam;

typedef struct s_light
{
	t_vector		translation;
	double			bright;
	t_color			color;
	struct s_light	*next;
}	t_light;

typedef struct s_ambient
{
	double	bright;
	t_color	color;
}	t_ambient;

t_obj	*create_obj_node(void);
void	calc_transf_matr(t_obj *obj);

#endif