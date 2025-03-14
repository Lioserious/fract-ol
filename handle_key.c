/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:48:45 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/14 16:32:35 by lihrig           ###   ########.fr       */
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

// Hilfsfunktion für die Farbschemawechsel
void	handle_color_change(t_fractal *fractal, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
	{
		fractal->color_scheme = (fractal->color_scheme + 1) % 4;
		if(fractal->fractal_type == 1)
			render_mandelbrot(fractal);
		else if(fractal->fractal_type == 2)
			render_julia(fractal);
	}
}

// Hilfsfunktion für den Reset
void	handle_reset(t_fractal *fractal, mlx_key_data_t keydata)
{
	if (fractal->fractal_type == 1 && keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	{
		fractal->min_re = -2.0;
		fractal->max_re = 1.0;
		fractal->min_im = -1.5;
		fractal->max_im = 1.5;
		fractal->max_iter = 100;
		render_mandelbrot(fractal);
	}
	if(fractal->fractal_type == 2 && keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	{
		fractal->julia_im = fractal->julia_im_cpy;
		fractal->julia_re = fractal->julia_re_cpy;
		fractal->min_re = -2.0;
		fractal->max_re = 1.0;
		fractal->min_im = -1.5;
		fractal->max_im = 1.5;
		fractal->max_iter = 100;
		render_julia(fractal);
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
