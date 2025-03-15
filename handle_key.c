/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:48:45 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/15 12:40:35 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Hilfsfunktion für die Navigation
void	handle_navigation(t_fractal *fractal, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_view(fractal, 0, 1);
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_view(fractal, 0, -1);
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_view(fractal, -1, 0);
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_view(fractal, 1, 0);
}

// Hilfsfunktion für den Reset
void	handle_reset(t_fractal *fractal, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	{
		if (fractal->fractal_type == 1)
			reset_mandelbrot(fractal);
		else if (fractal->fractal_type == 2)
			reset_julia(fractal);
		else if (fractal->fractal_type == 3)
			reset_burning_ship(fractal);
	}
}
void	handle_colour_parameters(t_fractal *fractal, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
	{

	}
	if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
	{

	}
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
	{

	}
}

// Hauptfunktion für Tastatureingaben
void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractal->mlx);
	handle_navigation(fractal, keydata);
	handle_color_change(fractal, keydata);
	handle_reset(fractal, keydata);
}
