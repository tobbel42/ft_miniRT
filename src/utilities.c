#include "mini_rt.h"

unsigned int	serial_color(t_color *color)
{
	unsigned int	c;
	unsigned int	temp;

	c = 0;
	temp = (int)floor(color->val[R]);
	if (temp > 255)
		temp = 255;
	c += temp;
	c = c << 8;
	temp = (int)floor(color->val[G]);
	if (temp > 255)
		temp = 255;
	c += temp;
	c = c << 8;
	temp = (int)floor(color->val[B]);
	if (temp > 255)
		temp = 255;
	c += temp;
	return (c);
}
