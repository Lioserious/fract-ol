/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:01:59 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/13 19:01:44 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "lib/Libft/libft.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 512
# define HEIGHT 512

// struct speichert die werte welche fuer die Bearbeitung wichtig sind
// int fractal_type; 1: Mandelbrot, 2: Julia, 3: Weiteres Fraktal
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
	int			fractal_type;
	double		julia_re;
	double		julia_im;
	int			color_scheme;
}				t_fractal;

// fuer den Mathematischen teil
typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

t_fractal		*init_fractal(void);
int				init_mlx(t_fractal *fractal);
t_complex		map_pixel_to_complex(t_fractal *fractal, int x, int y);
void			render_mandelbrot(t_fractal *fractal);
int				calculate_mandelbrot(t_complex c, int max_iter);
void			zoom_in(t_fractal *fractal, int x, int y);
void			zoom_out(t_fractal *fractal, int x, int y);
void			move_view(t_fractal *fractal, int dx, int dy);
void			handle_key(mlx_key_data_t keydata, void *param);
void			handle_mouse(mouse_key_t button, action_t action,
					modifier_key_t mods, void *param);
void			handle_scroll(double xdelta, double ydelta, void *param);
void			handle_close(void *param);
void			setup_hooks(t_fractal *fractal);
void			handle_resize(int32_t width, int32_t height, void *param);
int				calculate_color(t_fractal *fractal, int iter);
int				color_scheme_grayscale(double t);
int				color_scheme_red(double t);
int				color_scheme_blue(double t);
int				color_scheme_psychedelic(double t);
void			render_julia(t_fractal *fractal);
#endif