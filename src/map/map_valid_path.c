/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 04:56:09 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/31 15:17:51 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	foodfill(char *tmp_map, size_t col, size_t start_pos, size_t goal_pos)
{
	if (tmp_map[start_pos] == '1' || tmp_map[start_pos] == 'v')
		return (0);
	if (start_pos == goal_pos)
		return (1);
	tmp_map[start_pos] = 'v';
	if (foodfill(tmp_map, col, start_pos + col, goal_pos) ||
		foodfill(tmp_map, col, start_pos - col, goal_pos) ||
		foodfill(tmp_map, col, start_pos + 1, goal_pos) ||
		foodfill(tmp_map, col, start_pos - 1, goal_pos))
		return (1);
	return (0);
}

short	map_valid_path(t_map *map)
{
	char	*tmp_map;
	size_t	len;

	len = ft_strlen(map->txt);
	tmp_map = malloc(sizeof(char) * (len + 1));
	if (!tmp_map)
		return (1);
	ft_strlcpy(tmp_map, map->txt, len + 1);
	if (!foodfill(tmp_map, map->col, map->pos_player[0], map->pos_exit[0]))
	{
		free(tmp_map);
		return (0);
	}
	free(tmp_map);
	return (1);
}