/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:21:05 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/29 01:19:02 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_animation_monsters(t_mlx *mlx, t_img *img, t_map *map)
{
	size_t	i;
	size_t	col;
	size_t	row;
	size_t	pos;

	i = 0;
	while (i < map->count_monster)
	{
		pos = map->pos_monster[i];
		col = IMG_WIDTH * (pos % map->col);
		row = IMG_WIDTH * (pos / map->col);
		mlx_put_image_to_window(mlx->mlx_id, mlx->window, img->monster[img->monster_frame_index], col, row);
		i++;
	}
	img->monster_frame_index = (img->monster_frame_index + 1) % FRAME_COUNT;
}

int	main_loop_animation(t_mlx *mlx)
{
	static size_t	frame_count;

	if (!frame_count)
		frame_count = 0;
	if (frame_count > ANIM_SPEED)
	{
		render_animation_monsters(mlx, mlx->img, mlx->map);
		frame_count = 0;
	}
	frame_count++;
	return (0);
}