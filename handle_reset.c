/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:15:29 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/14 17:17:58 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_mandelbrot(t_fractal *fractal)
{
	fractal->min_re = -2.0;
	fractal->max_re = 1.0;
	fractal->min_im = -1.5;
	fractal->max_im = 1.5;
	fractal->max_iter = 100;
	render_mandelbrot(fractal);
}

void	reset_julia(t_fractal *fractal)
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

void	reset_burning_ship(t_fractal *fractal)
{
	fractal->min_re = -2.0;
	fractal->max_re = 1.0;
	fractal->min_im = -1.5;
	fractal->max_im = 1.5;
	fractal->max_iter = 100;
	render_burning_ship(fractal);
}
