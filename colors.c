/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:35:48 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/15 13:33:43 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_scheme_grayscale(double t)
{
	int	gray;

	gray = (int)(t * 255);
	return (((gray << 16) | (gray << 8) | gray) << 8 | 0xFF);
}

// Funktion für rotes Farbschema
int	color_scheme_red(double t, t_fractal *fractal)
{
	int	r;
	int	g;
	int	b;

	r = (int)(t * fractal->color_param_r);
	g = (int)(t * (fractal->color_param_g / 2.55));
	b = (int)(t * (fractal->color_param_b / 12.75));
	return (((r << 16) | (g << 8) | b) << 8 | 0xFF);
}

// Funktion für blaues Farbschema
int	color_scheme_blue(double t, t_fractal *fractal)
{
	int	r;
	int	g;
	int	b;

	r = (int)(t * (fractal->color_param_r / 12.75));
	g = (int)(t * (fractal->color_param_g / 2.55));
	b = (int)(t * fractal->color_param_b);
	return (((r << 16) | (g << 8) | b) << 8 | 0xFF);
}

// Funktion für psychedelisches Farbschema
int	color_scheme_psychedelic(double t, t_fractal *fractal)
{
	int	r;
	int	g;
	int	b;

	r = (int)(sin(t * (fractal->color_param_r / 17)) * 127.5 + 127.5);
	g = (int)(sin((t * (fractal->color_param_g / 17) + 2)) * 127.5 + 127.5);
	b = (int)(sin((t * (fractal->color_param_b / 17) + 4)) * 127.5 + 127.5);
	return (((r << 16) | (g << 8) | b) << 8 | 0xFF);
}

// Hilfsfunktion für die Farbschemawechsel
void	handle_color_change(t_fractal *fractal, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
	{
		fractal->color_scheme = (fractal->color_scheme + 1) % 4;
		if (fractal->fractal_type == 1)
			render_mandelbrot(fractal);
		else if (fractal->fractal_type == 2)
			render_julia(fractal);
		else if (fractal->fractal_type == 3)
			render_burning_ship(fractal);
	}
}
