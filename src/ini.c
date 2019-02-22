#include "fractol.h"

void	put_pxl_to_img(t_fractol *data, int x, int y, int color)
{
	if (data->x < WIDTH && data->y < WIDTH)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void	fract_calc(t_fractol *data)
{
	if (data->it_max < 0)
		data->it_max = 0;
	if (data->fract == 0)
		mandelbrot_pthread(data);
	else if (data->fract == 1)
		julia_pthread(data);
	else if (data->fract == 2)
		burningship_pthread(data);
}

void	fract_init(t_fractol *data)
{
	if (data->fract == 0)
	{
		INIT5(data->it_max, 50, data->zoom, 375, data->x1, -2,
				data->y1, -1.3, data->color, 2050);
	}
	else if (data->fract == 1)
	{
		INIT5(data->it_max, 50, data->zoom, 250, data->x1, -2.0,
				data->y1, -1.9, data->color, 265);
		INIT3(data->c_r, 0.285, data->c_i, 0.01, data->julia_mouse, 1);
	}
	else if (data->fract == 2)
	{
		INIT5(data->it_max, 50, data->zoom, 220, data->x1, -2.2,
				data->y1, -2.5, data->color, 265);
	}
	fract_calc(data);
}

int		fract_comp(char **argv, t_fractol *data)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		data->fract = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		data->fract = 1;
	else if (ft_strcmp(argv[1], "burningship") == 0)
		data->fract = 2;
	else
	{
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"");
		return (0);
	}
	return (1);
}

void	run_fractal(t_fractol *data, char **argv)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bpp, &data->sl, &data->endian);
	if ((fract_comp(argv, data)) == 0)
		ft_close();
	fract_init(data);
	mlx_hook(data->win, 6, 1L < 6, mouse_julia, data);
	mlx_hook(data->win, 17, 0L, ft_close, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_loop(data->mlx);
}
