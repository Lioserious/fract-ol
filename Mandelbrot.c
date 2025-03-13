/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:39:17 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/13 15:52:47 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	calculate_mandelbrot(t_complex c, int max_iter)
{
	int		i;
	double	temp;
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
