/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:39:17 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/13 18:44:53 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_mandelbrot(t_complex c, int max_iter)
{
	int			i;
	double		temp;
	t_complex	z;

	z.real = 0.0;
	z.imag = 0.0;
	i = 0;
	while (i < max_iter && (z.real * z.real + z.imag * z.imag) < 4.0)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp;
		i++;
	}
	return (i);
}

int	calculate_julia(t_complex z, t_complex c, int max_iter)
{
	int		i;
	double	temp;

	i = 0;
	while (i < max_iter && (z.real * z.real + z.imag * z.imag) < 4.0)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp;
		i++;
	}
	return (i);
}

void	render_julia(t_fractal *fractal)
{
	int			x;
	int			y;
	t_complex	z;
	t_complex	c;
	int			iter;

	c.real = fractal->julia_re;
	c.imag = fractal->julia_im;
	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			z = map_pixel_to_complex(fractal, x, y);
			iter = calculate_julia(z, c, fractal->max_iter);
			mlx_put_pixel(fractal->img, x, y, calculate_color(fractal, iter));
			x++;
		}
		y++;
	}
}

