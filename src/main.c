#include "mini_rt.h"
//following headers are just for debugging
#include "inter.h"
void	initialize_data(void)
{
	t_data	*data;

	data = get_data();
	ft_memset(data, 0, sizeof(t_data));
}

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

void	create_new_image(void)
{
	t_cam	cam;

	cam = init_camera(IMG_X, IMG_Y);
	render_img(cam);
	mlx_put_image_to_window(get_data()->mlx_ptr,
		get_data()->mlx_win, get_data()->mlx_img, 0, 0);
	mlx_loop(get_data()->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	initialize_data();
	data = get_data();
	input_parse(argc, argv);
	init_img(IMG_X, IMG_Y);
	data->cams->transform = get_translation_matrix(0, 0, 0);
	create_new_image();
	return (EXIT_SUCCESS);
}
