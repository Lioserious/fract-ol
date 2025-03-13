/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:28:02 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/13 17:13:36 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_fractal	*fractal;

	fractal = init_fractal();
	if (!fractal)
		return (1);
	if (!init_mlx(fractal))
	{
		free(fractal);
		return (1);
	}
	setup_hooks(fractal);
	render_mandelbrot(fractal);
	mlx_loop(fractal->mlx);
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_terminate(fractal->mlx);
	free(fractal);
	return (0);
}
