/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:34:24 by svovchyn          #+#    #+#             */
/*   Updated: 2019/02/27 11:23:47 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_to_image(t_fract *f, int x, int y, int color)
{
	if (f->x < WIDTH && f->y < WIDTH)
	{
		color = mlx_get_color_value(f->mlx, color);
		ft_memcpy(f->img_ptr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void	f_calc(t_fract *f)
{
	if (f->iter_max < 0)
		f->iter_max = 0;
	if (f->fractal == 0)
		m_pthread(f);
	else if (f->fractal == 1)
		j_pthread(f);
	else if (f->fractal == 2)
		b_pthread(f);
	else if (f->fractal == 3)
		t_pthread(f);
}

void	f_ini(t_fract *f)
{
	if (f->fractal == 0)
	{
		INIT5(f->iter_max, 50, f->scale, 220, f->xs, -2,
				f->ys, -1.3, f->color, 771);
	}
	else if (f->fractal == 1)
	{
		INIT5(f->iter_max, 50, f->scale, 160, f->xs, -1.87,
				f->ys, -1.87, f->color, 771);
		INIT3(f->xr, 0.285, f->zyr, 0.01, f->julia_mouse, 1);
	}
	else if (f->fractal == 2)
	{
		INIT5(f->iter_max, 50, f->scale, 150, f->xs, -2.0,
				f->ys, -2.0, f->color, 1537);
	}
	else if (f->fractal == 3)
	{
		INIT5(f->iter_max, 50, f->scale, 150, f->xs, -2,
				f->ys, -2, f->color, 523001);
	}
	f_calc(f);
}

int		f_pick(char **argv, t_fract *f)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		f->fractal = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		f->fractal = 1;
	else if (ft_strcmp(argv[1], "burningship") == 0)
		f->fractal = 2;
	else if (ft_strcmp(argv[1], "tricorn") == 0)
		f->fractal = 3;
	else
	{
		ft_putendl("Usage: /fractol mandelbrot|julia|burningship|tricorn");
		return (0);
	}
	return (1);
}

void	run_fractal(t_fract *f, char **argv)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, WIDTH, "Fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, WIDTH);
	f->img_ptr = mlx_get_data_addr(f->img,
			&f->bpp, &f->sl, &f->endian);
	if ((f_pick(argv, f)) == 0)
		bye();
	f_ini(f);
	mlx_hook(f->win, 6, 1L < 6, julia_mouse, f);
	mlx_hook(f->win, 17, 0L, bye, f);
	mlx_key_hook(f->win, keyboard_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_loop(f->mlx);
}
