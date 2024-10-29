/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:07:28 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/29 00:36:27 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	map_randomize_patern_void(t_mlx *mlx, t_img *img, size_t col, size_t row)
{
	size_t	random_i;

	random_i = random_index_0_5(col * row);
	mlx_put_image_to_window(mlx->mlx_id, mlx->window, img->flat[random_i], col, row);
	return (1);
}

short	map_init_render(t_map *map, t_mlx *mlx, t_img *img)
{
	size_t	pos;
	size_t	row;
	size_t	col;

	pos = 0;
	while (pos < (map->col * map->row))
	{
		col = IMG_WIDTH * (pos % map->col);
		row = IMG_WIDTH * (pos / map->col);
		if (map->txt[pos] == WALL)
			mlx_put_image_to_window(mlx->mlx_id, mlx->window, img->wall, col, row);
		if (map->txt[pos] == ITEM)
			mlx_put_image_to_window(mlx->mlx_id, mlx->window, img->item, col, row);
		if (map->txt[pos] == VOID)
			map_randomize_patern_void(mlx, img, col, row);
		if (map->txt[pos] == START)
			mlx_put_image_to_window(mlx->mlx_id, mlx->window, img->player_start, col, row);
		if (map->txt[pos] == EXIT)
			mlx_put_image_to_window(mlx->mlx_id, mlx->window, img->exit_close, col, row);
		// if (map->txt[pos] == MONSTER)
		// 	render_animation_monsters(mlx, img, col, row);
		pos++;
	}
	return (1);
}
