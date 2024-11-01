/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move_monsters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:08:18 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/01 07:11:03 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Moves the monster towards the player.
** 
** - Differences in position (delta).
** - Decide on the best axis to move.
** - Move the monster towards the player, trying alternate moves if blocked.
** - Move turn by turn (Time with main loop mlx animation)
** - Define turn player (After 2 turn)
*/
void	put_image_at_pos(t_mlx *mlx, t_monster *monster, size_t col, size_t row)
{
	if (is_item_pos(mlx->map, monster->pos))
		mlx_put_image_to_window(mlx->mlx_id, mlx->window,
			mlx->img->item, col * IMG_WIDTH, row * IMG_WIDTH);
	else
		map_randomize_patern_void(mlx, mlx->img,
			col * IMG_WIDTH, row * IMG_WIDTH);
}

void	update_monster_position(t_mlx *mlx, t_monster *monster, size_t new_pos)
{
	size_t	new_col;
	size_t	new_row;

	new_col = new_pos % mlx->map->col;
	new_row = new_pos / mlx->map->col;
	mlx->map->pos_monster[monster->id] = new_row * mlx->map->col + new_col;
	mlx_put_image_to_window(mlx->mlx_id, mlx->window,
		mlx->img->monster[0], new_col * IMG_WIDTH, new_row * IMG_WIDTH);
	if (mlx->map->pos_monster[monster->id] == *mlx->map->pos_player)
		attack_to_player(mlx, mlx->map);
}

int	move_monster_to_position(t_mlx *mlx, t_monster *monster, size_t new_pos)
{
	size_t	col;
	size_t	row;
	size_t	new_col;
	size_t	new_row;

	col = monster->col;
	row = monster->row;
	new_col = new_pos % mlx->map->col;
	new_row = new_pos / mlx->map->col;
	if (!is_wall_pos_or_door_close(mlx->map, new_col, new_row)
		&& !is_monster_pos(mlx->map, new_row * mlx->map->col + new_col)
		&& new_col < mlx->map->col && new_row < mlx->map->row)
	{
		put_image_at_pos(mlx, monster, col, row);
		update_monster_position(mlx, monster, new_pos);
		return (1);
	}
	return (0);
}

void	try_alternate_move(t_mlx *mlx, t_monster *monster,
							int delta_col, int delta_row)
{
	if (delta_col != 0)
	{
		if (delta_row > 0)
			move_monster_to_position(mlx, monster,
				monster->pos + mlx->map->col);
		else if (delta_row < 0)
			move_monster_to_position(mlx, monster,
				monster->pos - mlx->map->col);
	}
	else if (delta_row != 0)
	{
		if (delta_col > 0)
			move_monster_to_position(mlx, monster, monster->pos + 1);
		else if (delta_col < 0)
			move_monster_to_position(mlx, monster, monster->pos - 1);
	}
}

void	follow_player(t_mlx *mlx, int p_col, int p_row, t_monster *monster)
{
	int	delta_col;
	int	delta_row;

	delta_col = p_col - monster->col;
	delta_row = p_row - monster->row;
	if (ft_abs(delta_col) >= ft_abs(delta_row))
	{
		if ((delta_col > 0 && !move_monster_to_position(mlx,
					monster, monster->pos + 1))
			|| (delta_col < 0 && !move_monster_to_position(mlx,
					monster, monster->pos - 1)))
			try_alternate_move(mlx, monster, delta_col, delta_row);
	}
	else
	{
		if ((delta_row > 0 && !move_monster_to_position(mlx,
					monster, monster->pos + mlx->map->col))
			|| (delta_row < 0 && !move_monster_to_position(mlx,
					monster, monster->pos - mlx->map->col)))
			try_alternate_move(mlx, monster, delta_col, delta_row);
	}
}

static void	is_turn_player(t_mlx *mlx)
{
	static size_t	turn_monster;

	if (!turn_monster)
		turn_monster = 0;
	turn_monster++;
	if (turn_monster == 2)
	{
		mlx->is_player_turn = 1;
		set_turn_banner(mlx);
		turn_monster = 0;
		return ;
	}
	return ;
}

short	move_monsters_ia(t_mlx *mlx, t_map *map)
{
	t_monster		*monsters;
	static size_t	i_frame = 0;
	int				pos_player_col;
	int				pos_player_row;

	pos_player_col = map->pos_player[0] % map->col;
	pos_player_row = map->pos_player[0] / map->col;
	monsters = initialize_monsters(map);
	if (!monsters)
		return (1);
	follow_player(mlx, pos_player_col, pos_player_row, &monsters[i_frame]);
	i_frame = (i_frame + 1) % map->count_monster;
	if (i_frame == 0)
		is_turn_player(mlx);
	free(monsters);
	return (0);
}
