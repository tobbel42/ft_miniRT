#ifndef WINDOW_H
# define WINDOW_H

# define KEY_ESC 53
# define KLICK_LEFT 1
# define KLICK_RIGHT 2
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125

# define DESTROY_NOTIFY 17

int	key_hook(int keycode);
int	close_window(void);

#endif