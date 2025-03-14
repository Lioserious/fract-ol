/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:28:02 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/14 15:10:36 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int parse_args(int argc, char **argv, t_fractal *fractal)
{
	(void)argc;
    if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
    {
        fractal->fractal_type = 1;
        return (1);
    }
    else if (ft_strncmp(argv[1], "julia", 5) == 0)
    {
        fractal->fractal_type = 2;
        return (1);
    }
    return (0);
}

void print_usage(void)
{
	ft_printf("Usage: ./fractol [type] [parameters]\n");
    ft_printf("Types:\n");
    ft_printf("  mandelbrot    : Renders the Mandelbrot set\n");
    ft_printf("  julia [re] [im]: Renders the Julia set with given parameters\n");
    ft_printf("                   Default: -0.7 0.27\n");
    ft_printf("Examples:\n");
    ft_printf("  ./fractol mandelbrot\n");
    ft_printf("  ./fractol julia -0.7 0.27\n");
    ft_printf("  ./fractol julia -0.8 0.156\n");
    ft_printf("  ./fractol julia -0.4 0.6\n");
    ft_printf("  ./fractol julia 0.285 0.01\n");
}


int main(int argc, char **argv)
{
    t_fractal *fractal;
    
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
	{
		free(fractal);
		return (1);
	}
	if(fractal->fractal_type == 1)
		render_mandelbrot(fractal);
	if(fractal->fractal_type == 2)
		render_julia(fractal);
	setup_hooks(fractal);
	mlx_loop(fractal->mlx);
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_terminate(fractal->mlx);
	free(fractal);
    return (0);
}
// int	main(void)
// {
// 	t_fractal	*fractal;

// 	fractal = init_fractal();
// 	if (!fractal)
// 		return (1);
// 	if (!init_mlx(fractal))
// 	{
// 		free(fractal);
// 		return (1);
// 	}
// 	setup_hooks(fractal);
// 	render_mandelbrot(fractal);
// 	mlx_loop(fractal->mlx);
// 	mlx_delete_image(fractal->mlx, fractal->img);
// 	mlx_terminate(fractal->mlx);
// 	free(fractal);
// 	return (0);
// }
