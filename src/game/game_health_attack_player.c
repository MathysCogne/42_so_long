/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_health_attack_player.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:06:45 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/30 18:46:47 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	attack_to_player(t_mlx *mlx, t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->count_monster)
	{
		if (*map->pos_player == map->pos_monster[i])
		{
			map->health_player = map->health_player - 1;
			draw_health(mlx, map, mlx->img);
			map->pos_monster[i] = map->col * map->row;
		}
		i++;
	}
	return (1);
}

short	draw_health(t_mlx *mlx, t_map *map, t_img *img)
{
	size_t	col;
	size_t	row;

	col = ((map->col - 1) / 2) * IMG_WIDTH;
	row = (map->row - 1) * IMG_WIDTH;
	if (map->health_player == 3)
		mlx_put_image_to_window(mlx->mlx_id, mlx->window,
			img->ui_health[3], col, row);
	else if (map->health_player == 2)
		mlx_put_image_to_window(mlx->mlx_id, mlx->window,
			img->ui_health[2], col, row);
	else if (map->health_player == 1)
		mlx_put_image_to_window(mlx->mlx_id, mlx->window,
			img->ui_health[1], col, row);
	else if (map->health_player <= 0)
		mlx_put_image_to_window(mlx->mlx_id, mlx->window,
			img->ui_health[0], col, row);
	return (1);
}
