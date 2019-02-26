/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:34:11 by svovchyn          #+#    #+#             */
/*   Updated: 2019/02/26 16:45:24 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			tricorn_math(t_fract *f)
{
	f->xr = f->x / f->scale + f->xs;
	f->zyr = f->y / f->scale + f->ys;
	f->zxr = 0;
	f->yr = 0;
	f->iter = 0;
	while (f->zxr * f->zxr + f->yr *
			f->yr < 4 && f->iter < f->iter_max)
	{
		f->temp = f->zxr * f->zxr - f->yr * f->yr + f->xr;
		f->yr = -2 * (f->zxr * f->yr) + f->zyr;
		f->zxr = f->temp;
		f->iter++;
	}
	if (f->iter == f->iter_max)
		pixel_to_image(f, f->x, f->y, 0x000000);
	else
		pixel_to_image(f, f->x, f->y, f->color * f->iter);
}

void			*tricorn(void *tab)
{
	int			temp;
	t_fract		*f;

	f = (t_fract *)tab;
	f->x = 0;
	temp = f->y;
	while (f->x < WIDTH)
	{
		f->y = temp;
		while (f->y < f->y_top)
		{
			tricorn_math(f);
			f->y++;
		}
		f->x++;
	}
	return (tab);
}

void			t_pthread(t_fract *f)
{
	int			i;
	t_fract		tab[NUMBER];
	pthread_t	t[NUMBER];

	i = 0;
	while (i < NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)f, sizeof(t_fract));
		tab[i].y = T_WIDTH * i;
		tab[i].y_top = T_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, tricorn, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
