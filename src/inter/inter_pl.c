#include "inter.h"

/*
//finds the intersection of a ray and a plane
//returns t for the vector ray= O + d * t , if the plane and ray intersect
//negative values are returned for no intersection,
//or if the intersection lays behind the ray origin (aka camera origin)
//a ray which is on the plane (infinite intersections) is treated,
// as if there are no intersections
*/

/*
//using the normal plane (root {0, 0, 0}, normal {0, 0, 1})
//to calculate the intersection the point has to be calulated with the
//transformed ray, than be retransformed
*/
double	inter_pl(t_obj *plane, t_ray ray)
{
	double		div;
	double		t;
	t_ray		ray_trans;
	t_vector	normal;

	ray_trans = ray_to_local(plane, ray);
	normal = vec_init(VECTOR, 0.0, 0.0, 1.0);
	div = vec_dot(normal, ray_trans.direction);
	if (div == 0)
		t = -1.0;
	else
		t = -1.0 * vec_dot(ray_trans.origin, normal) / div;
	return (t);
}
