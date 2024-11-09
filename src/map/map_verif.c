/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 03:35:41 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/09 20:43:01 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	map_valid_char(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->txt[i])
	{
		if (map->txt[i] != '0' && map->txt[i] != '1' && map->txt[i] != 'C'
			&& map->txt[i] != 'M' && map->txt[i] != 'E'
			&& map->txt[i] != 'P' && map->txt[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

short	map_contain_exit_start_item(t_map *map)
{
	if (map->count_exit != 1)
		return (1);
	if (map->count_start != 1)
		return (1);
	if (map->count_item == 0)
		return (1);
	return (0);
}

short	map_rectangular(t_map *map)
{
	if (map->col == map->row)
		return (1);
	return (0);
}

short	map_closed_wall(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->col)
	{
		if (map->txt[i] != WALL)
			return (1);
		if (map->txt[(map->col * (map->row - 1)) + i] != WALL)
			return (1);
		i++;
	}
	i = 0;
	while (i < map->row)
	{
		if (map->txt[i * map->col] != WALL)
			return (1);
		if (map->txt[i * map->col + (map->col - 1)] != WALL)
			return (1);
		i++;
	}
	return (0);
}

short	map_verif(t_map *map)
{
	if (map_valid_char(map))
		return (1);
	if (map_contain_exit_start_item(map))
		return (2);
	if (map_rectangular(map))
		return (3);
	if (map_closed_wall(map))
		return (4);
	if (map_valid_path(map))
		return (5);
	return (0);
}
