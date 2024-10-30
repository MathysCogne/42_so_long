/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_verif_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:34:41 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/30 18:27:24 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	is_wall_pos_or_door_close(t_map *map, size_t col, size_t row)
{
	size_t	i;
	size_t	pos;

	pos = row * map->col + col;
	if (pos == map->pos_exit[0] && map->collect_item != map->count_item)
		return (1);
	i = 0;
	while (i < map->count_wall)
	{
		if (pos == map->pos_wall[i])
			return (1);
		i++;
	}
	return (0);
}

short	is_item_pos(t_map *map, size_t pos)
{
	size_t	i;

	i = 0;
	while (i < map->count_item)
	{
		if (pos == map->pos_item[i])
		{
			if (pos == *map->pos_player)
				map->pos_item[i] = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

short	is_door_open_pos(t_map *map, size_t pos)
{
	if (pos == map->pos_exit[0] && map->collect_item == map->count_item)
		return (1);
	return (0);
}

short	is_monster_pos(t_map *map, size_t pos)
{
	size_t	i;

	i = 0;
	while (i < map->count_monster)
	{
		if (pos == map->pos_monster[i])
			return (1);
		i++;
	}
	return (0);
}
