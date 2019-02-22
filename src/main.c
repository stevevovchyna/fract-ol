#include "fractol.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fractol	*data;

	if (!(data = (t_fractol *)malloc(sizeof(t_fractol))))
		return (-1);
	if (argc == 2)
		run_fractal(data, argv);
	else
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"");
	return (0);
}
