#include "matrix.h"
#include <stdio.h>
double	vec_dot_matrix(t_matrix ar1, t_matrix ar2)
{
	int		i;
	double	res;

	i = 0;
	res = 0;
	while (i < 3)
	{
		res += ar1.val[i][0] * ar2.val[i][0];
		i++;
	}
	return (res);
}

//only for debugging as printf is used
void	print_matrix(t_matrix mat)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			printf("%.2f\t", mat.val[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
	printf("\n");
}

t_vector	matrix_vec_multiplication(t_matrix mat, t_vector vec)
{
	t_vector	res;

	res.val[X] = mat.val[0][0] * vec.val[X]
		+ mat.val[0][1] * vec.val[Y]
		+ mat.val[0][2] * vec.val[Z]
		+ mat.val[0][3] * vec.val[W];
	res.val[Y] = mat.val[1][0] * vec.val[X]
		+ mat.val[1][1] * vec.val[Y]
		+ mat.val[1][2] * vec.val[Z]
		+ mat.val[1][3] * vec.val[W];
	res.val[Z] = mat.val[2][0] * vec.val[X]
		+ mat.val[2][1] * vec.val[Y]
		+ mat.val[2][2] * vec.val[Z]
		+ mat.val[2][3] * vec.val[W];
	res.val[W] = mat.val[3][0] * vec.val[X]
		+ mat.val[3][1] * vec.val[Y]
		+ mat.val[3][2] * vec.val[Z]
		+ mat.val[3][3] * vec.val[W];
	return (res);
}
//t_matrix	vec_to_matrix(t_vec *vec)
//{
//	t_matrix	mat;
//	int	i;

//	mat = create_matrix(1, 4);
//	i = 0;
//	while (i < 3)
//	{
//		mat.val[0][i] = vec->val[i];
//		i++;
//	}
//	mat.val[0][3] = 1.0;
//	return (mat);
//}

void	init_matrix(t_matrix *mat)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			mat->val[row][col] = 0.0;
			col++;
		}
		row++;
	}
}
