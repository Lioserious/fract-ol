/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:21:58 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/12 15:22:36 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

t_fractal	*init_fractal(void)
{
	t_fractal *fractal;

	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractal)
		return (NULL);

	// Standardwerte setzen
	fractal->width = WIDTH;
	fractal->height = HEIGHT;
	fractal->min_re = -2.0;
	fractal->max_re = 1.0;
	fractal->min_im = -1.5;
	fractal->max_im = 1.5;
	fractal->max_iter = 100;
	fractal->fractal_type = 1; // Standard: Mandelbrot
	// fractal->julia_re = -0.7;  // Standard Julia-Parameter
	// fractal->julia_im = 0.27;  // Standard Julia-Parameter
	fractal->color_scheme = 0; // Standard-Farbschema
	fractal->mlx = NULL;
	fractal->img = NULL;

	return (fractal);
}
