#include "mini_rt.h"
#include "matrix.h"

void	matrix_transponation(t_matrix *mat, t_matrix *result)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			result->val[row][col] = mat->val[col][row];
			col++;
		}
		row++;
	}
}

t_matrix	matrix_multiplication(t_matrix mat1, t_matrix mat2)
{
	int			row;
	int			col;
	int			i;
	t_matrix	res;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			i = 0;
			res.val[row][col] = 0.0;
			while (i < 4)
			{
				res.val[row][col] += mat1.val[row][i] * mat2.val[i][col];
				i++;
			}
			col++;
		}
		row++;
	}
	return (res);
}

double	determinante(t_matrix *matrix, int size)
{
	int			i;
	int			sign;
	double		res;
	t_matrix	submat;

	res = 0;
	if (size == 1)
	{
		return (matrix->val[0][0]);
	}
	i = 0;
	while (i < size)
	{
		submat = submatrix(matrix, 0, i, size);
		sign = pow(-1, i);
		res += sign * matrix->val[0][i] * determinante(&submat, size - 1);
		i++;
	}
	return (res);
}

void	cofactor_matrix(t_matrix *mat, t_matrix *cof, int size)
{
	int			row;
	int			col;
	int			sign;
	t_matrix	submat;

	row = 0;
	while (row < size)
	{
		col = 0;
		sign = pow(-1, row);
		while (col < size)
		{
			init_matrix(&submat);
			submat = submatrix(mat, row, col, size);
			cof->val[row][col] = sign * determinante(&submat, size - 1);
			col++;
			sign *= -1;
		}
		row++;
	}
}

t_matrix	matrix_skalar_multiplication(double scalar, t_matrix mat)
{
	t_matrix	res;
	int			row;
	int			col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			res.val[row][col] = scalar * mat.val[row][col];
			col++;
		}
		row++;
	}
	return (res);
}
