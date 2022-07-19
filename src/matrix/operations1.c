#include "mini_rt.h"
#include "matrix.h"

t_matrix	submatrix(t_matrix *mat, int row, int col, int size)
{
	int			i_row;
	int			i_col;
	t_matrix	sub_mat;

	i_row = 0;
	while (i_row < (size - 1))
	{
		i_col = 0;
		while (i_col < (size - 1))
		{
			if (i_row < row && i_col < col)
				sub_mat.val[i_row][i_col] = mat->val[i_row][i_col];
			else if (i_row < row && i_col >= col)
				sub_mat.val[i_row][i_col] = mat->val[i_row][i_col + 1];
			else if (i_row >= row && i_col < col)
				sub_mat.val[i_row][i_col] = mat->val[i_row + 1][i_col];
			else if (i_row >= row && i_col >= col)
				sub_mat.val[i_row][i_col] = mat->val[i_row + 1][i_col + 1];
			i_col++;
		}
		i_row++;
	}
	return (sub_mat);
}

// https://www.mathebibel.de/inverse-matrix-berechnen-mit-adjunkte
t_matrix	matrix_inverse(t_matrix *mat, int size)
{
	t_matrix	cof;
	t_matrix	transp;
	t_matrix	inv;
	double		det;

	init_matrix(&cof);
	init_matrix(&transp);
	init_matrix(&inv);
	det = determinante(mat, size);
	cofactor_matrix(mat, &cof, size);
	matrix_transponation(&cof, &transp);
	inv = matrix_skalar_multiplication(1 / det, transp);
	return (inv);
}

t_matrix	matrix_add(t_matrix a, t_matrix b)
{
	t_matrix	result;
	int			row;
	int			col;

	init_matrix(&result);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			result.val[row][col] = a.val[row][col] + b.val[row][col];
			col++;
		}
		row++;
	}
	return (result);
}

t_matrix	matrix_sub(t_matrix a, t_matrix b)
{
	t_matrix	result;
	int			col;
	int			row;

	init_matrix(&result);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			result.val[row][col] = a.val[row][col] - b.val[row][col];
			col++;
		}
		row++;
	}
	return (result);
}
