#include "mini_rt.h"
#include "window.h"

//better use exit over main function, therefor calling loop end?
int	key_hook(int keycode)
{
	t_data		*data;
	t_matrix	help;

	data = get_data();
	if (keycode == KEY_ESC)
		exit_end("Esc key closed window");
	if (keycode == KEY_RIGHT)
		help = get_rotation_y_matrix(-0.2);
	if (keycode == KEY_LEFT)
		help = get_rotation_y_matrix(0.2);
	if (keycode == KEY_UP)
		help = get_rotation_x_matrix(-0.2);
	if (keycode == KEY_DOWN)
		help = get_rotation_x_matrix(0.2);
	data->cams->transform = matrix_multiplication(data->cams->transform, help);
	create_new_image();
	return (EXIT_SUCCESS);
}

//better use exit over main function, therefor calling loop end?
int	close_window(void)
{
	exit_end("X closed window");
	return (EXIT_SUCCESS);
}
