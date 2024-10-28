/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 04:17:28 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/28 06:08:06 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mlx_keypress(int keycode, t_mlx *mlx)
{
	ft_printf("[EVENT] Keycode: %i\n", keycode);
	if (keycode == KEY_ESC)
		ft_mlx_close_window(mlx);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(mlx, 0, -1);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(mlx, 0, 1);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(mlx, -1, 0);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(mlx, 1, 0);
	return (0);
}

int	ft_mlx_close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_id, mlx->window);
	ft_put_exrror("CLOSE ESC");
	return (0);
}

short	ft_mlx_setup_hook(t_mlx *mlx)
{
	mlx_key_hook(mlx->window, ft_mlx_keypress, mlx);
	mlx_hook(mlx->window, 17, 0, ft_mlx_close_window, mlx);
	return (1);
}
