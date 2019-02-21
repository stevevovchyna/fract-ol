#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include <stdlib.h>
# include <pthread.h>
# define WIDTH 1000
# define THREAD_WIDTH 5
# define THREAD_NUMBER 200

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			endian;
	int			sl;
	int			bpp;
	int			fract;
	int			color;
	int			julia_mouse;
	int			x;
	int			y;
	int			y_max;
	int			it;
	int			it_max;
	int			show_text;
	long double		zoom;
	long double		x1;
	long double		y1;
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	long double		tmp;
}				t_fractol;


int				key_hook(int keycode, t_fractol *data);
int				key_hook2(int keycode, t_fractol *data);
void			ft_zoom(int x, int y, t_fractol *data);
void			ft_dezoom(int x, int y, t_fractol *data);
int				mouse_hook(int mousecode, int x, int y, t_fractol *data);

void			mandelbrot_init(t_fractol *data);
void			mandelbrot_calc(t_fractol *data);
void			*mandelbrot(void *tab);
void			mandelbrot_pthread(t_fractol *data);

int				mouse_julia(int x, int y, t_fractol *data);
void			julia_init(t_fractol *data);
void			julia_calc(t_fractol *data);
void			*julia(void *tab);
void			julia_pthread(t_fractol *data);

void			burningship_init(t_fractol *data);
void			burningship_calc(t_fractol *data);
void			*burningship(void *tab);
void			burningship_pthread(t_fractol *data);

int				ft_close(void);
void			put_pxl_to_img(t_fractol *data, int x, int y, int color);
void			put_text(t_fractol *data);

void			fract_calc(t_fractol *data);
void			fract_init(t_fractol *data);
void			mlx_win_init(t_fractol *data);
int				fract_comp(char **av, t_fractol *data);

#endif
