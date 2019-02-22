#include "fractol.h"

int		key_hook(int key, t_fractol *data)
{
	if (key == ESC)
	{
		system("leaks fractol");
		exit(1);
	}
	if (key == RESETSPACE)
		fract_init(data);
	key == PLUS ? data->it_max += 10 : 0;
	key == MINUS ? data->it_max -= 10 : 0;
	key == LEFT ? data->x1 -= 30 / data->zoom : 0;
	key == RIGTH ? data->x1 += 30 / data->zoom : 0;
	key == DOWN ? data->y1 += 30 / data->zoom : 0;
	key == UP ? data->y1 -= 30 / data->zoom : 0;
	key == KISLATA ? data->color = 1677216 : 0;
	key == COLOR2 ? data->color = 2050 : 0;
	key == COLOR3 ? data->color = 265 : 0;
	key == FREEZEJULIA ? data->julia_mouse = !data->julia_mouse : 0;
	fract_calc(data);
	return (0);
}

int		mouse_hook(int mousekey, int x, int y, t_fractol *data)
{
	if (mousekey == WHEELDOWN || mousekey == LEFTMOUSE)
	{
		data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.3));
		data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.3));
		data->zoom *= 1.3;
		data->it_max++;
	}
	else if (mousekey == WHEELUP || mousekey == RIGHTMOUSE)
	{
		data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom / 1.3));
		data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.3));
		data->zoom /= 1.3;
		data->it_max--;
	}
	fract_calc(data);
	return (0);
}
