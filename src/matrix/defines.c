#include "matrix.h"

t_matrix	get_translation_matrix(double x, double y, double z)
{
	t_matrix	transform;

	init_matrix(&transform);
	transform.val[0][0] = 1.0;
	transform.val[1][1] = 1.0;
	transform.val[2][2] = 1.0;
	transform.val[3][3] = 1.0;
	transform.val[0][3] = x;
	transform.val[1][3] = y;
	transform.val[2][3] = z;
	return (transform);
}

t_matrix	get_scale_matrix(double x, double y, double z)
{
	t_matrix	transform;

	init_matrix(&transform);
	transform.val[0][0] = x;
	transform.val[1][1] = y;
	transform.val[2][2] = z;
	transform.val[3][3] = 1.0;
	return (transform);
}

t_matrix	get_rotation_x_matrix(double rad)
{
	t_matrix	transform;
	double		sina;
	double		cosa;

	sina = sin(rad);
	cosa = cos(rad);
	init_matrix(&transform);
	transform.val[0][0] = 1.0;
	transform.val[1][1] = cosa;
	transform.val[1][2] = -sina;
	transform.val[2][1] = sina;
	transform.val[2][2] = cosa;
	transform.val[3][3] = 1.0;
	return (transform);
}

t_matrix	get_rotation_y_matrix(double rad)
{
	t_matrix	transform;
	double		sina;
	double		cosa;

	sina = sin(rad);
	cosa = cos(rad);
	init_matrix(&transform);
	transform.val[0][0] = cosa;
	transform.val[0][2] = sina;
	transform.val[1][1] = 1.0;
	transform.val[2][0] = -sina;
	transform.val[2][2] = cosa;
	transform.val[3][3] = 1.0;
	return (transform);
}

t_matrix	get_rotation_z_matrix(double rad)
{
	t_matrix	transform;
	double		sina;
	double		cosa;

	sina = sin(rad);
	cosa = cos(rad);
	init_matrix(&transform);
	transform.val[0][0] = cosa;
	transform.val[0][1] = -sina;
	transform.val[1][0] = sina;
	transform.val[1][1] = cosa;
	transform.val[2][2] = 1.0;
	transform.val[3][3] = 1.0;
	return (transform);
}
