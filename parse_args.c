/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:45:21 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/15 12:24:05 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// takes all variations of writing
int	ft_strncmp_mod(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ft_tolower(s1[i]) == ft_tolower(s2[i]) && s1[i] != '\0'
		&& s2[i] != '\0')
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned char)ft_tolower(s1[i])
			- (unsigned char)ft_tolower(s2[i]));
}

// takes care of Julia arguments and checks if they are valid
int	parse_julia_params(int argc, char **argv, t_fractal *fractal)
{
	double	re;
	double	im;

	re = fractal->julia_re;
	im = fractal->julia_im;
	if (argc >= 3)
		re = ft_atof(argv[2]);
	if (argc >= 4)
		im = ft_atof(argv[3]);
	if (re < -2.0 || re > 2.0 || im < -2.0 || im > 2.0)
	{
		ft_printf("\nFailure: Julia Parameter have to be between -2 and 2\n\n");
		return (0);
	}
	fractal->julia_re = re;
	fractal->julia_im = im;
	fractal->julia_im_cpy = fractal->julia_im;
	fractal->julia_re_cpy = fractal->julia_re;
	return (1);
}

int	parse_args(int argc, char **argv, t_fractal *fractal)
{
	if (argc < 2)
		return (0);
	if (ft_strncmp_mod(argv[1], "mandelbrot", 10) == 0)
	{
		fractal->fractal_type = 1;
		return (1);
	}
	else if (ft_strncmp_mod(argv[1], "julia", 5) == 0)
	{
		fractal->fractal_type = 2;
		return (parse_julia_params(argc, argv, fractal));
	}
	else if (ft_strncmp_mod(argv[1], "ship", 5) == 0)
	{
		fractal->fractal_type = 3;
		return (1);
	}
	return (0);
}
