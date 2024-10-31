/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:00:35 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/31 14:10:29 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Moves the player.
** 
** - Validate new position (no walls/doors).
** - Update player's position on map.
** - Call events after movement.
** - Increment move / Collected Item / Check attack monster / health
** - Define turn monsters (Turn is define with heatlh player (3hp = 3 + 1 turn))
*/
static void	launch_event_move(t_mlx *mlx, size_t pos_player)
{
	mlx->map->count_move++;
	if (is_item_pos(mlx->map, pos_player))
	{
		mlx->map->collect_item++;
		draw_digit_item(mlx, mlx->map->collect_item);
		if (mlx->map->collect_item == mlx->map->count_item)
			ft_mlx_put_image_to_window(mlx, mlx->img->exit_open,
				mlx->map->pos_exit[0]);
	}
	if (is_door_open_pos(mlx->map, pos_player))
		game_win(mlx);
	if (is_monster_pos(mlx->map, pos_player))
		attack_to_player(mlx, mlx->map);
	if (mlx->map->health_player <= 0)
		game_over(mlx);
	draw_digit_move(mlx, mlx->map->count_move);
}

static void	is_turn_monsters(t_mlx *mlx)
{
	static size_t	turn_player;

	if (!turn_player)
		turn_player = 0;
	turn_player++;
	if (turn_player == mlx->map->health_player + 1)
	{
		mlx->is_player_turn = 0;
		set_turn_banner(mlx);
		turn_player = 0;
		return ;
	}
	return ;
}

short	move_player(t_mlx *mlx, int to_col, int to_row)
{
	size_t	col;
	size_t	row;
	size_t	new_col;
	size_t	new_row;

	col = *mlx->map->pos_player % mlx->map->col;
	row = *mlx->map->pos_player / mlx->map->col;
	new_col = col + to_col;
	new_row = row + to_row;
	if (new_col < mlx->map->col && new_row < mlx->map->row
		&& !is_wall_pos_or_door_close((*mlx).map, new_col, new_row))
	{
		map_randomize_patern_void(mlx, mlx->img,
			col * IMG_WIDTH, row * IMG_WIDTH);
		*mlx->map->pos_player = new_row * mlx->map->col + new_col;
		mlx_put_image_to_window(mlx->mlx_id, mlx->window, mlx->img->player[0],
			new_col * IMG_WIDTH, new_row * IMG_WIDTH);
		launch_event_move(mlx, *mlx->map->pos_player);
		is_turn_monsters(mlx);
	}
	return (1);
}
