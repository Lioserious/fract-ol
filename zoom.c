/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:51:25 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/15 09:41:23 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Punkt unter dem Mauszeiger finden
// Zoom-Faktor (z.B. 0.5 bedeutet halb so große Ansicht = 2x Zoom)
// Neue Grenzen berechnen, wobei der Punkt unter dem Mauszeiger fixiert bleibt
// Neues Zentrum berechnen
// Neu rendern
void	zoom_in(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	double		zoom_factor;
	double		width;
	double		height;

	c = map_pixel_to_complex(fractal, x, y);
	zoom_factor = 0.5;
	width = (fractal->max_re - fractal->min_re) * zoom_factor;
	height = (fractal->max_im - fractal->min_im) * zoom_factor;
	fractal->min_re = c.real - width / 2;
	fractal->max_re = c.real + width / 2;
	fractal->min_im = c.imag - height / 2;
	fractal->max_im = c.imag + height / 2;
	if (fractal->fractal_type == 1)
		render_mandelbrot(fractal);
	else if (fractal->fractal_type == 2)
		render_julia(fractal);
	else if (fractal->fractal_type == 3)
		render_burning_ship(fractal);
}

// Punkt unter dem Mauszeiger finden
// Zoom-Faktor (z.B. 2.0 bedeutet doppelt so große Ansicht = 0.5x Zoom)
// Neue Grenzen berechnen, wobei der Punkt unter dem Mauszeiger fixiert bleibt
// Neues Zentrum berechnen
// Neu rendern
void	zoom_out(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	double		zoom_factor;
	double		width;
	double		height;

	c = map_pixel_to_complex(fractal, x, y);
	zoom_factor = 2.0;
	width = (fractal->max_re - fractal->min_re) * zoom_factor;
	height = (fractal->max_im - fractal->min_im) * zoom_factor;
	fractal->min_re = c.real - width / 2;
	fractal->max_re = c.real + width / 2;
	fractal->min_im = c.imag - height / 2;
	fractal->max_im = c.imag + height / 2;
	if (fractal->fractal_type == 1)
		render_mandelbrot(fractal);
	else if (fractal->fractal_type == 2)
		render_julia(fractal);
	else if (fractal->fractal_type == 3)
		render_burning_ship(fractal);
}

// Bewegungsgeschwindigkeit (0.05 = 5% des sichtbaren Bereichs pro Tastendruck)
// Breite und Höhe des sichtbaren Bereichs
// Verschieben der Grenzen basierend auf der Richtung
// Neu rendern
void	move_view(t_fractal *fractal, int dx, int dy)
{
	double	speed;
	double	width;
	double	height;
	double	delta_x;
	double	delta_y;

	speed = 0.05;
	width = fractal->max_re - fractal->min_re;
	height = fractal->max_im - fractal->min_im;
	delta_x = width * speed * dx;
	delta_y = height * speed * dy;
	fractal->min_re += delta_x;
	fractal->max_re += delta_x;
	fractal->min_im += delta_y;
	fractal->max_im += delta_y;
	if (fractal->fractal_type == 1)
		render_mandelbrot(fractal);
	else if (fractal->fractal_type == 2)
		render_julia(fractal);
	else if (fractal->fractal_type == 3)
		render_burning_ship(fractal);
}

void	handle_resize(int32_t width, int32_t height, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	fractal->width = width;
	fractal->height = height;
	mlx_delete_image(fractal->mlx, fractal->img);
	fractal->img = mlx_new_image(fractal->mlx, width, height);
	if (!fractal->img)
		return ;
	if (mlx_image_to_window(fractal->mlx, fractal->img, 0, 0) < 0)
	{
		mlx_delete_image(fractal->mlx, fractal->img);
		return ;
	}
	if (fractal->fractal_type == 1)
		render_mandelbrot(fractal);
	else if (fractal->fractal_type == 2)
		render_julia(fractal);
	else if (fractal->fractal_type == 3)
		render_burning_ship(fractal);
}
