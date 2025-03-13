/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:21:58 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/13 15:45:18 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

// Standardwerte setzen
t_fractal	*init_fractal(void)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractal)
		return (NULL);
	fractal->width = WIDTH;
	fractal->height = HEIGHT;
	fractal->min_re = -2.0;
	fractal->max_re = 1.0;
	fractal->min_im = -1.5;
	fractal->max_im = 1.5;
	fractal->max_iter = 100;
	fractal->fractal_type = 1;
	// fractal->julia_re = -0.7;  // Standard Julia-Parameter
	// fractal->julia_im = 0.27;  // Standard Julia-Parameter
	fractal->color_scheme = 0; // Standard-Farbschema
	fractal->mlx = NULL;
	fractal->img = NULL;
	return (fractal);
}

int	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init(fractal->width, fractal->height, "Fract-ol Test",
			true);
	if (!fractal->mlx)
		return (0);
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	if (!fractal->img)
	{
		mlx_terminate(fractal->mlx);
		return (0);
	}
	if (mlx_image_to_window(fractal->mlx, fractal->img, 0, 0) < 0)
	{
		mlx_delete_image(fractal->mlx, fractal->img);
		mlx_terminate(fractal->mlx);
		return (0);
	}
	return (1);
}

// X-Koordinate: Bereich von [0, width-1] wird auf [min_re, max_re] abgebildet
// Y-Koordinate: Bereich von [0, height-1] wird auf [min_im, max_im] abgebildet
// Beachte, dass die Y-Achse auf dem Bildschirm nach unten geht,
// aber in der komplexen Ebene nach oben
complex	map_pixel_to_complex(t_fractal *fractal, int x, int y)
{
	complex	c;

	c.real = fractal->min_re + (double)x / (fractal->width - 1)
		* (fractal->max_re - fractal->min_re);
	c.imag = fractal->max_im - (double)y / (fractal->height - 1)
		* (fractal->max_im - fractal->min_im);
	return (c);
}

// 0x000000FF;  Schwarz für Punkte im Set
int	calculate_color(t_fractal *fractal, int iter)
{
	int		color;
	double	t;

	if (iter == fractal->max_iter)
		color = 0x000000FF;
	else
	{
		t = (double)iter / fractal->max_iter;
		color = (((int)(t * 255) << 16) | ((int)(t * 255) << 8) | (int)(t
					* 255)) << 8 | 0xFF;
	}
	return (color);
}

void	render_mandelbrot(t_fractal *fractal)
{
	int		x;
	int		y;
	complex	c;
	int		iter;

	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			c = map_pixel_to_complex(fractal, x, y);
			iter = calculate_mandelbrot(c, fractal->max_iter);
			mlx_put_pixel(fractal->img, x, y, calculate_color(fractal, iter));
			x++;
		}
		y++;
	}
}
