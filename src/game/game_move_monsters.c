/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move_monsters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:08:18 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/30 00:34:01 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short move_monsters(t_mlx *mlx, t_monster *monster, size_t new_pos)
{
	size_t col = monster->col;
	size_t row = monster->row;
	size_t new_col = new_pos % mlx->map->col;
	size_t new_row = new_pos / mlx->map->col;

	if (!is_wall_pos_or_door_close(mlx->map, new_col, new_row) && !is_monster_pos(mlx->map, new_row * mlx->map->col + new_col))
	{
		if (new_col < mlx->map->col && new_row < mlx->map->row)
		{
			map_randomize_patern_void(mlx, mlx->img, col * IMG_WIDTH, row * IMG_WIDTH);
			mlx->map->pos_monster[monster->id] = new_row * mlx->map->col + new_col;
			mlx_put_image_to_window(mlx->mlx_id, mlx->window, mlx->img->monster[0], new_col * IMG_WIDTH, new_row * IMG_WIDTH);
		}
	}
	return (1);
}

short	follow_player(t_mlx *mlx, int pos_player_col, int pos_player_row, t_monster *monster)
{
	int	delta_col = pos_player_col - monster->col;
	int	delta_row = pos_player_row - monster->row;

	if (ft_abs(delta_col) >= ft_abs(delta_row))
	{
		if (delta_col > 0) // RIGHT
			move_monsters(mlx, monster, monster->pos + 1);
		else if (delta_col < 0) // LEFT
			move_monsters(mlx, monster, monster->pos - 1);
	}
	else
	{
		if (delta_row > 0) // DOWN
			move_monsters(mlx, monster, monster->pos + mlx->map->col);
		else if (delta_row < 0) // UP
			move_monsters(mlx, monster, monster->pos - mlx->map->col);
	}
	return (1);
}

short	move_monsters_ia(t_mlx *mlx, t_map *map)
{
	size_t		id = 0;
	t_monster	monster[map->count_monster];
	int pos_player_col;
	int pos_player_row;

	pos_player_col = map->pos_player[0] % map->col;
	pos_player_row = map->pos_player[0] / map->col;
	while (id < map->count_monster)
	{
		monster[id].id = id;
		monster[id].pos = map->pos_monster[id];
		monster[id].col = monster[id].pos % map->col;
		monster[id].row = monster[id].pos / map->col;
		follow_player(mlx, pos_player_col, pos_player_row, &monster[id]);
		id++;
	}
	return (0);
}

