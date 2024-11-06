/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 04:17:28 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/01 07:07:49 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** KEYHOOKS events for controls player and monster actions.
** Closes the game window
** Sets up hooks for rendering
*/
int	ft_mlx_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		ft_mlx_close_window(mlx);
	if ((keycode == KEY_ENTER || keycode == KEY_SPACE) && !mlx->is_player_turn)
		move_monsters_ia(mlx, mlx->map);
	if ((keycode == KEY_W || keycode == KEY_UP) && mlx->is_player_turn)
		move_player(mlx, 0, -1);
	if ((keycode == KEY_S || keycode == KEY_DOWN) && mlx->is_player_turn)
		move_player(mlx, 0, 1);
	if ((keycode == KEY_A || keycode == KEY_LEFT) && mlx->is_player_turn)
		move_player(mlx, -1, 0);
	if ((keycode == KEY_D || keycode == KEY_RIGHT) && mlx->is_player_turn)
		move_player(mlx, 1, 0);
	return (0);
}

int	ft_mlx_close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_id, mlx->window);
	free_struct_img(mlx, mlx->img);
	mlx_loop_end(mlx->mlx_id);
	mlx_destroy_display(mlx->mlx_id);
	free_struct_map(mlx->map);
	free_struct_mlx(mlx);
	ft_msg_put_exrror(ERROR_MSG_EXIT_USER);
	return (0);
}

short	ft_mlx_setup_hook(t_mlx *mlx)
{
	draw_health(mlx, mlx->map, mlx->img);
	mlx_loop_hook(mlx->mlx_id, main_loop_animation, mlx);
	mlx_key_hook(mlx->window, ft_mlx_keypress, mlx);
	mlx_hook(mlx->window, 17, 0, ft_mlx_close_window, mlx);
	return (1);
}
