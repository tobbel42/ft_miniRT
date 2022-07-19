#include "mini_rt.h"

void	calc_transf_matr(t_obj *obj)
{
	t_matrix	unit_mat;

	unit_mat = get_scale_matrix(1, 1, 1);
	obj->trans_to_global = matrix_multiplication(
			(obj->parmas.translation), unit_mat);
	obj->trans_to_global = matrix_multiplication(
			(obj->trans_to_global), (obj->parmas.rotation_x));
	obj->trans_to_global = matrix_multiplication(
			(obj->trans_to_global), (obj->parmas.rotation_y));
	obj->trans_to_global = matrix_multiplication(
			(obj->trans_to_global), (obj->parmas.rotation_z));
	obj->trans_to_global = matrix_multiplication(
			(obj->trans_to_global), (obj->parmas.scale));
	obj->trans_to_local = matrix_inverse(&(obj->trans_to_global), 4);
}
