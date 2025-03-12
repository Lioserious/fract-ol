/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:01:59 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/12 16:45:59 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include "lib/Libft/libft.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 512
# define HEIGHT 512

// struct speichert die werte welche fuer die Bearbeitung wichtig sind
typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			width;
	int			height;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	int			max_iter;
	int fractal_type; // 1: Mandelbrot, 2: Julia, 3: Weiteres Fraktal
	double julia_re;  // Julia-Set Parameter
	double julia_im;  // Julia-Set Parameter
	int color_scheme; // Farbschema-Auswahl
}				t_fractal;

// fuer den Mathematischen teil
typedef struct
{
	double		real;
	double		imag;
}				Complex;

t_fractal	*init_fractal(void);
int	init_mlx(t_fractal *fractal);
Complex map_pixel_to_complex(t_fractal *fractal, int x, int y);
void render_mandelbrot(t_fractal *fractal);
int	calculate_mandelbrot(Complex c, int max_iter);


#endif