/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:34:24 by svovchyn          #+#    #+#             */
/*   Updated: 2019/03/13 18:19:00 by svovchyn         ###   ########.fr       */
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
	else if (f->fractal == 4)
		multi_pthread(f);
	else if (f->fractal == 5)
		livebrot_pthread(f);
}

void	f_ini(t_fract *f)
{
	if (f->fractal == 1 || f->fractal == 5)
	{
		INIT5(f->iter_max, 50, f->scale, 160, f->xs, -1.87,
				f->ys, -1.87, f->color, 21);
		INIT3(f->xr, 0.285, f->zyr, 0.01, f->julia_mouse, 1);
		if (!f->n)
			f->fractal == 5 ? f->n = 2 : 0;
	}
	else if (f->fractal == 0 || f->fractal == 2 || f->fractal == 3
			|| f->fractal == 4)
	{
		INIT5(f->iter_max, 50, f->scale, 150, f->xs, -2,
				f->ys, -2, f->color, 771);
	}
	f->fractal == 2 ? f->color = 1537 : 0;
	f->fractal == 3 ? f->color = 254686 : 0;
	f->fractal == 4 ? f->color = 521 : 0;
	f->fractal == 5 ? f->color = 1537 : 0;
	if (!f->n)
		f->fractal == 4 ? f->n = 10 : 0;
	f_calc(f);
}

int		f_pick(char **argv, t_fract *f, int n)
{
	if (ft_strcmp(argv[n], "mandelbrot") == 0)
		f->fractal = 0;
	else if (ft_strcmp(argv[n], "julia") == 0)
		f->fractal = 1;
	else if (ft_strcmp(argv[n], "burningship") == 0)
		f->fractal = 2;
	else if (ft_strcmp(argv[n], "tricorn") == 0)
		f->fractal = 3;
	else if (ft_strcmp(argv[n], "multibrot") == 0)
		f->fractal = 4;
	else if (ft_strcmp(argv[n], "livebrot") == 0)
		f->fractal = 5;
	else
	{
		warning();
		return (0);
	}
	return (1);
}

void	run_fractal(t_fract *f, int argc, char **argv, int n)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, WIDTH, "Fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, WIDTH);
	f->img_ptr = mlx_get_data_addr(f->img,
			&f->bpp, &f->sl, &f->endian);
	if ((f_pick(argv, f, n)) == 0)
		bye();
	argc == 2 ? helper() : 0;
	f_ini(f);
	mlx_hook(f->win, 6, 1L < 6, julia_mouse, f);
	mlx_hook(f->win, 17, 0L, bye, f);
	mlx_key_hook(f->win, keyboard_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_loop(f->mlx);
}
