#include "matrix.h"
#include <stdio.h>

t_matrix	test_matrix(void)
{
	t_matrix	mat;

	init_matrix(&mat);
	mat.val[0][0] = 4.0;
	mat.val[0][1] = 3.0;
	mat.val[1][0] = 5.0;
	mat.val[1][1] = 7.0;
	return (mat);
}

t_matrix	create_filled_matrix(int start)
{
	t_matrix	mat;
	int			row;
	int			col;

	row = 0;
	init_matrix(&mat);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			mat.val[row][col] = (row + start) * 10.0 + (col);
			col++;
		}
		row++;
	}
	return (mat);
}
