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
# define FREEZEJULIA 3
# define LEFTMOUSE 1
# define RIGHTMOUSE 2
# define WHEELUP 4
# define WHEELDOWN 5

# define INIT5(a, b, c, d, e, f, g, h, i, j) a = b; c = d; e = f; g = h; i = j;
# define INIT3(a, b, c, d, e, f) a = b; c = d; e = f;

typedef struct		s_fractol
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_ptr;
	int				endian;
	int				sl;
	int				bpp;
	int				fract;
	int				color;
	int				julia_mouse;
	int				x;
	int				y;
	int				y_max;
	int				it;
	int				it_max;
	int				show_text;
	long double		zoom;
	long double		x1;
	long double		y1;
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	long double		tmp;
}					t_fractol;

void				run_fractal(t_fractol *data, char **argv);

int					key_hook(int key, t_fractol *data);
void				zoom_in(int x, int y, t_fractol *data);
void				zoom_out(int x, int y, t_fractol *data);
int					mouse_hook(int mousekey, int x, int y, t_fractol *data);

void				mandelbrot_init(t_fractol *data);
void				mandelbrot_calc(t_fractol *data);
void				*mandelbrot(void *tab);
void				mandelbrot_pthread(t_fractol *data);

int					mouse_julia(int x, int y, t_fractol *data);
void				julia_init(t_fractol *data);
void				julia_calc(t_fractol *data);
void				*julia(void *tab);
void				julia_pthread(t_fractol *data);

void				burningship_init(t_fractol *data);
void				burningship_calc(t_fractol *data);
void				*burningship(void *tab);
void				burningship_pthread(t_fractol *data);

int					ft_close(void);
void				put_pxl_to_img(t_fractol *data, int x, int y, int color);
void				put_text(t_fractol *data);

void				fract_calc(t_fractol *data);
void				fract_init(t_fractol *data);
void				mlx_win_init(t_fractol *data);
int					fract_comp(char **argv, t_fractol *data);

#endif
