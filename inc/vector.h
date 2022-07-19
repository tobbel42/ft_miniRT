#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

# define R 0
# define G 1
# define B 2

# define X 0
# define Y 1
# define Z 2
# define W 3

# define VECTOR 0.0
# define COLOR 0.0
# define POINT 1.0

typedef struct s_vector
{
	double	val[4];
}	t_vector;

t_vector	vec_init(int type, double x, double y, double z);
double		vec_dot(t_vector ar1, t_vector ar2);
t_vector	vec_cross(int type, t_vector m1, t_vector m2);
t_vector	vec_matrix_normalize(t_vector a);
t_vector	vec_sub(int type, t_vector a, t_vector b);
t_vector	vec_add(int type, t_vector a, t_vector b);
t_vector	vec_scale(int type, double t, t_vector a);
t_vector	vec_normalize(int type, t_vector a);

#endif