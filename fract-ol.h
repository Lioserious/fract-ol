/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:01:59 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/12 14:21:16 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACT_OL_H
# define FRACT_OL_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "lib/MLX42/include/MLX42/MLX42.h"
#include "lib/Libft/libft.h"

#define WIDTH 512
#define HEIGHT 512

typedef struct s_fractal {
    mlx_t       *mlx;
    mlx_image_t *img;
    int         width;
    int         height;
    double      min_re;
    double      max_re;
    double      min_im;
    double      max_im;
    int         max_iter;
    int         fractal_type;  // 1: Mandelbrot, 2: Julia, 3: Weiteres Fraktal
    double      julia_re;      // Julia-Set Parameter
    double      julia_im;      // Julia-Set Parameter
    int         color_scheme;  // Farbschema-Auswahl
} t_fractal;

typedef struct {
    double real;
    double imag;
} Complex;

#endif