/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:34:15 by svovchyn          #+#    #+#             */
/*   Updated: 2019/03/13 17:50:20 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				julia_mouse(int x, int y, t_fract *f)
{
	if ((f->fractal == 1 && f->julia_mouse == 1) ||
		(f->fractal == 5 && f->julia_mouse == 1))
	{
		f->xr = x * 2;
		f->zyr = y * 2 - 800;
		f_calc(f);
	}
	return (0);
}

void			julia_math(t_fract *f)
{
	f->zxr = f->x / f->scale + f->xs;
	f->yr = f->y / f->scale + f->ys;
	f->iter = 0;
	while (f->zxr * f->zxr + f->yr
			* f->yr < 4 && f->iter < f->iter_max)
	{
		f->temp = f->zxr;
		f->zxr = f->zxr * f->zxr -
			f->yr * f->yr - 0.8 + (f->xr / WIDTH);
		f->yr = 2 * f->yr * f->temp + f->zyr / WIDTH;
		f->iter++;
	}
	if (f->iter == f->iter_max)
		pixel_to_image(f, f->x, f->y, 0x000000);
	else
		pixel_to_image(f, f->x, f->y, (f->color * f->iter));
}

void			*julia(void *arg)
{
	int			temp;
	t_fract		*f;

	f = (t_fract *)arg;
	f->x = 0;
	temp = f->y;
	while (f->x < WIDTH)
	{
		f->y = temp;
		while (f->y < f->y_top)
		{
			julia_math(f);
			f->y++;
		}
		f->x++;
	}
	return (arg);
}

void			j_pthread(t_fract *f)
{
	int			i;
	t_fract		arg[NUMBER];
	pthread_t	t[NUMBER];

	i = 0;
	while (i < NUMBER)
	{
		ft_memcpy((void*)&arg[i], (void*)f, sizeof(t_fract));
		arg[i].y = T_WIDTH * i;
		arg[i].y_top = T_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, julia, &arg[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
