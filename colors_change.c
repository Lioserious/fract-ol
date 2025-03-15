/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:17:05 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/15 13:30:11 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_red_parameter(t_fractal *fractal, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_I && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
	{
		fractal->color_param_r = (fractal->color_param_r + 10) % 256;
		if (fractal->fractal_type == 1)
			render_mandelbrot(fractal);
		else if (fractal->fractal_type == 2)
			render_julia(fractal);
		else if (fractal->fractal_type == 3)
			render_burning_ship(fractal);
	}
}

void	handle_green_parameter(t_fractal *fractal, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_O && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
	{
		fractal->color_param_g = (fractal->color_param_g + 10) % 256;
		if (fractal->fractal_type == 1)
			render_mandelbrot(fractal);
		else if (fractal->fractal_type == 2)
			render_julia(fractal);
		else if (fractal->fractal_type == 3)
			render_burning_ship(fractal);
	}
}

void	handle_blue_parameter(t_fractal *fractal, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_P && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
	{
		fractal->color_param_b = (fractal->color_param_b + 10) % 256;
		if (fractal->fractal_type == 1)
			render_mandelbrot(fractal);
		else if (fractal->fractal_type == 2)
			render_julia(fractal);
		else if (fractal->fractal_type == 3)
			render_burning_ship(fractal);
	}
}
