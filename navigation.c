/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:43:14 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/12 17:59:20 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

// ESC zum Beenden
// Pfeiltasten zur Navigation
void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractal->mlx);
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_view(fractal, 0, -1);
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_view(fractal, 0, 1);
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_view(fractal, -1, 0);
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_view(fractal, 1, 0);
}
// Mausposition holen
// Links-Klick zum Zoomen
// Rechts-Klick zum Rauszoomen
void	handle_mouse(mouse_key_t button, action_t action, modifier_key_t mods,
		void *param)
{
	t_fractal	*fractal;

	fractal = param;
	int x, y;
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
void	handle_scroll(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	int x, y;
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
}
