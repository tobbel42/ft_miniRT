#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>
# include "../lib/libft/libft.h"
# include "vector.h"
# include <math.h>

/*
a11	a12	a13	a14
a21	a22	a23	a24
a31	a32	a33	a34
a41	a42	a43	a44
*/
typedef struct s_matrix
{
	double	val[4][4];
}	t_matrix;

void		init_matrix(t_matrix *mat);

void		matrix_transponation(t_matrix *mat, t_matrix *result);
t_matrix	matrix_multiplication(t_matrix mat1, t_matrix mat2);
t_matrix	matrix_skalar_multiplication(double scalar, t_matrix mat);
t_matrix	matrix_inverse(t_matrix *mat, int size);

t_matrix	get_translation_matrix(double x, double y, double z);
t_matrix	get_scale_matrix(double x, double y, double z);
t_matrix	get_rotation_x_matrix(double rad);
t_matrix	get_rotation_y_matrix(double rad);
t_matrix	get_rotation_z_matrix(double rad);

t_matrix	submatrix(t_matrix *mat, int col, int row, int size);
double		determinante(t_matrix *matrix, int size);
void		cofactor_matrix(t_matrix *mat, t_matrix *cof, int size);

t_matrix	matrix_add(t_matrix a, t_matrix b);
t_matrix	matrix_sub(t_matrix a, t_matrix b);

t_vector	matrix_vec_multiplication(t_matrix mat, t_vector vec);

#endif