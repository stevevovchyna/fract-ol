/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:34:29 by svovchyn          #+#    #+#             */
/*   Updated: 2019/03/13 17:50:32 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include <stdlib.h>
# include <pthread.h>
# define WIDTH 600
# define T_WIDTH 5
# define NUMBER 120

# define ESC 53
# define PLUS 69
# define MINUS 78
# define LEFT 123
# define RIGTH 124
# define DOWN 125
# define UP 126
# define RESETSPACE 49
# define KISLATA 18
# define COLOR2 19
# define COLOR3 20
# define COLOR4 21
# define COLOR5 23
# define COLOR6 22
# define FREEZEJULIA 3
# define LEFTMOUSE 1
# define RIGHTMOUSE 2
# define WHEELUP 4
# define WHEELDOWN 5
# define MANDELBROT 46
# define JULIA 38
# define BURNINGSHIP 11
# define TRICORN 17
# define MULTIBROT 45
# define LIVEBROT 37
# define POWUP 116
# define POWDOWN 121

# define INIT5(a, b, c, d, e, f, g, h, i, j) a = b; c = d; e = f; g = h; i = j;
# define INIT3(a, b, c, d, e, f) a = b; c = d; e = f;

typedef struct		s_fract
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_ptr;
	int				endian;
	int				sl;
	int				bpp;
	int				fractal;
	int				color;
	int				julia_mouse;
	int				live_mouse;
	int				x;
	int				y;
	int				n;
	int				y_top;
	int				iter;
	int				iter_max;
	int				i;
	long double		scale;
	long double		xs;
	long double		ys;
	long double		xr;
	long double		zyr;
	long double		zxr;
	long double		yr;
	long double		temp;
}					t_fract;

int					bye(void);
void				run_two_fractals(t_fract *f, char **argv);

void				pixel_to_image(t_fract *f, int x, int y, int color);
void				f_calc(t_fract *f);
void				f_ini(t_fract *f);
int					f_pick(char **argv, t_fract *f, int n);
void				run_fractal(t_fract *f, int argc, char **argv, int n);

int					keyboard_hook(int key, t_fract *f);
void				pauwa(int key, t_fract *f);
void				selector(int key, t_fract *f);
int					mouse_hook(int mousekey, int x, int y, t_fract *f);

void				mandelbrot_math(t_fract *f);
void				*mandelbrot(void *arg);
void				m_pthread(t_fract *f);

int					julia_mouse(int x, int y, t_fract *f);
void				julia_math(t_fract *f);
void				*julia(void *arg);
void				j_pthread(t_fract *f);

void				tricorn_math(t_fract *f);
void				*tricorn(void *arg);
void				t_pthread(t_fract *f);

void				burningship_math(t_fract *f);
void				*burningship(void *arg);
void				b_pthread(t_fract *f);

void				helper(void);
void				warning(void);

void				multi_pthread(t_fract *f);
void				*multibrot(void *arg);
void				multibrot_math(t_fract *f);

void				livebrot_pthread(t_fract *f);
void				*livebrot(void *arg);
void				livebrot_math(t_fract *f);

#endif
