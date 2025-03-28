/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:43:14 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/13 17:13:44 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Mausposition holen
// Links-Klick zum Zoomen
// Rechts-Klick zum Rauszoomen
// modifier key t koennen Maustasten konfiguriert werden
void	handle_mouse(mouse_key_t button, action_t action,
		modifier_key_t mod __attribute__((unused)), void *param)
{
	t_fractal	*fractal;
	int			x;
	int			y;

	fractal = param;
	if (action != MLX_PRESS)
		return ;
	mlx_get_mouse_pos(fractal->mlx, &x, &y);
	if (button == MLX_MOUSE_BUTTON_LEFT)
		zoom_in(fractal, x, y);
	else if (button == MLX_MOUSE_BUTTON_RIGHT)
		zoom_out(fractal, x, y);
}

// Mausposition holen
// Nach oben scrollen = Reinzoomen
// Nach unten scrollen = Rauszoomen
// x delta unused weil es nur fuer trackpads verwendet wird
void	handle_scroll(double xdelta __attribute__((unused)), double ydelta,
		void *param)
{
	t_fractal	*fractal;
	int			x;
	int			y;

	fractal = param;
	mlx_get_mouse_pos(fractal->mlx, &x, &y);
	if (ydelta > 0)
		zoom_in(fractal, x, y);
	else if (ydelta < 0)
		zoom_out(fractal, x, y);
}

// Ressourcen freigeben
void	handle_close(void *param)
{
	t_fractal	*fractal;

	fractal = param;
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_terminate(fractal->mlx);
	free(fractal);
	exit(0);
}

void	setup_hooks(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx, handle_key, fractal);
	mlx_mouse_hook(fractal->mlx, handle_mouse, fractal);
	mlx_scroll_hook(fractal->mlx, handle_scroll, fractal);
	mlx_close_hook(fractal->mlx, handle_close, fractal);
	mlx_resize_hook(fractal->mlx, handle_resize, fractal);
}
