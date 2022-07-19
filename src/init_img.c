#include "mini_rt.h"
#include "window.h"

//todo protect agains fails
void	init_img(int size_x, int size_y)
{
	t_data	*data;

	data = get_data();
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, size_x, size_y, "miniRT");
	data->mlx_img = mlx_new_image(
			data->mlx_ptr, size_x, size_y);
	data->mlx_img_ptr = mlx_get_data_addr(
			data->mlx_img, &data->mlx_bpp, &data->mlx_ll, &data->mlx_endian);
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_hook(data->mlx_win, DESTROY_NOTIFY, 1L << 17,
		close_window, data);
}
