/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:00:35 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/28 06:07:21 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	is_wall(t_map *map, size_t col, size_t row)
{
	size_t	i;
	size_t	pos;

	pos = row * map->col + col;
	i = 0;
	while (i < map->count_wall)
	{
		if (pos == map->pos_wall[i])
			return (1);
		i++;
	}
	return (0);
}

short	move_player(t_mlx *mlx, int to_col, int to_row)
{
	t_map	*map;
	t_img	*img;
	size_t	col;
	size_t	row;
	size_t	new_col;
	size_t	new_row;

	map = mlx->map;
	img = mlx->img;
	col = *map->pos_player % map->col;
	row = *map->pos_player / map->col;
	new_col = col + to_col;
	new_row = row + to_row;
	if (new_col < map->col && new_row < map->row && !is_wall(map, new_col, new_row))
	{
		if (!img)
			ft_printf("DEBILE");
		mlx_put_image_to_window(mlx->mlx_id, mlx->window, img->i_void, col * IMG_WIDTH, row * IMG_WIDTH);

		*map->pos_player = new_row * map->col + new_col;
		if (!img->player)
			ft_printf("DEBILE");
		mlx_put_image_to_window(mlx->mlx_id, mlx->window, img->player, new_col * IMG_WIDTH, new_row * IMG_WIDTH);
	}
	return (1);
}
