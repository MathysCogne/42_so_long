/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 04:56:09 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/09 20:43:40 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	foodfill(char *tmp_map, size_t col,
	size_t start_pos, size_t goal_pos)
{
	size_t	count;

	count = 0;
	if (tmp_map[start_pos] == '1' || tmp_map[start_pos] == 'v')
		return (0);
	if (tmp_map[start_pos] == 'C')
		count = 1;
	tmp_map[start_pos] = 'v';
	count += foodfill(tmp_map, col, start_pos + col, goal_pos);
	count += foodfill(tmp_map, col, start_pos - col, goal_pos);
	count += foodfill(tmp_map, col, start_pos + 1, goal_pos);
	count += foodfill(tmp_map, col, start_pos - 1, goal_pos);
	if (start_pos == goal_pos)
		return (count + 1);
	return (count);
}

short	map_valid_path(t_map *map)
{
	char	*tmp_map;
	size_t	item;
	size_t	len;

	len = ft_strlen(map->txt);
	tmp_map = malloc(sizeof(char) * (len + 1));
	if (!tmp_map)
		return (1);
	ft_strlcpy(tmp_map, map->txt, len + 1);
	item = foodfill(tmp_map, map->col, map->pos_player[0], map->pos_exit[0]);
	free(tmp_map);
	if (item == map->count_item + 1)
		return (0);
	return (1);
}
