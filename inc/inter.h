#ifndef INTER_H
# define INTER_H
# include "mini_rt.h"
# include "matrix.h"

double	inter_pl(t_obj *plane, t_ray ray);
double	inter_sp(t_obj *sphere, t_ray ray);
double	inter_cy(t_obj *cyl, t_ray ray);
double	inter_c_pl(t_obj *pl, t_ray ray);

#endif
