/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:51:25 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/13 13:54:20 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

// Punkt unter dem Mauszeiger finden
// Zoom-Faktor (z.B. 0.5 bedeutet halb so große Ansicht = 2x Zoom)
// Neue Grenzen berechnen, wobei der Punkt unter dem Mauszeiger fixiert bleibt
// Neues Zentrum berechnen
// Neu rendern
void zoom_in(t_fractal* fractal, int x, int y)
{
    complex c = map_pixel_to_complex(fractal, x, y);
    double zoom_factor = 0.5;
    double width = (fractal->max_re - fractal->min_re) * zoom_factor;
    double height = (fractal->max_im - fractal->min_im) * zoom_factor;
    fractal->min_re = c.real - width / 2;
    fractal->max_re = c.real + width / 2;
    fractal->min_im = c.imag - height / 2;
    fractal->max_im = c.imag + height / 2;
    render_mandelbrot(fractal);
}

// Punkt unter dem Mauszeiger finden
// Zoom-Faktor (z.B. 2.0 bedeutet doppelt so große Ansicht = 0.5x Zoom)
// Neue Grenzen berechnen, wobei der Punkt unter dem Mauszeiger fixiert bleibt
// Neues Zentrum berechnen
// Neu rendern
void zoom_out(t_fractal* fractal, int x, int y)
{
    complex c = map_pixel_to_complex(fractal, x, y);
    double zoom_factor = 2.0;
    double width = (fractal->max_re - fractal->min_re) * zoom_factor;
    double height = (fractal->max_im - fractal->min_im) * zoom_factor;
    fractal->min_re = c.real - width / 2;
    fractal->max_re = c.real + width / 2;
    fractal->min_im = c.imag - height / 2;
    fractal->max_im = c.imag + height / 2;
    render_mandelbrot(fractal);
}

// Bewegungsgeschwindigkeit (0.05 = 5% des sichtbaren Bereichs pro Tastendruck)
// Breite und Höhe des sichtbaren Bereichs
// Verschieben der Grenzen basierend auf der Richtung
// Neu rendern
void move_view(t_fractal* fractal, int dx, int dy)
{
    double speed = 0.05;
    double width = fractal->max_re - fractal->min_re;
    double height = fractal->max_im - fractal->min_im;
    double delta_x = width * speed * dx;
    double delta_y = height * speed * dy;
    fractal->min_re += delta_x;
    fractal->max_re += delta_x;
    fractal->min_im += delta_y;
    fractal->max_im += delta_y;
    render_mandelbrot(fractal);
}