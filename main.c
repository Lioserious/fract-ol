/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:28:02 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/20 14:26:01 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_fractal(t_fractal *fractal)
{
	free(fractal);
}

void	print_usage(void)
{
	ft_printf("Usage: ./fractol [type] [parameters]\n");
	ft_printf("Types:\n");
	ft_printf("  mandelbrot    : Renders the Mandelbrot set\n");
	ft_printf("  julia [re] [im]: Renders the Julia");
	ft_printf("   ship : Renders the Burning Ship fractal\n");
	ft_printf("set with given parameters\n");
	ft_printf("                   Default: -0.7 0.27\n");
	ft_printf("Examples:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia -0.7 0.27\n");
	ft_printf("  ./fractol julia -0.8 0.156\n");
	ft_printf("  ./fractol julia -0.4 0.6\n");
	ft_printf("  ./fractol julia 0.285 0.01\n");
	ft_printf("  ./fractol ship\n");
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = init_fractal();
	if (!fractal)
		return (1);
	if (argc == 1 || !parse_args(argc, argv, fractal))
	{
		print_usage();
		free(fractal);
		return (1);
	}
	if (!init_mlx(fractal))
		return (free_fractal(fractal), 1);
	if (fractal->fractal_type == 1)
		render_mandelbrot(fractal);
	else if (fractal->fractal_type == 2)
		render_julia(fractal);
	else if (fractal->fractal_type == 3)
		render_burning_ship(fractal);
	setup_hooks(fractal);
	mlx_loop(fractal->mlx);
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_terminate(fractal->mlx);
	free(fractal);
	return (0);
}
