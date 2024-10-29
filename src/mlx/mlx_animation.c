/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:21:05 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/30 00:32:40 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_animation_monsters(t_mlx *mlx, t_img *img, t_map *map)
{
	static size_t	i_frame;
	size_t	i;
	size_t	col;
	size_t	row;
	size_t	pos;

	if (!i_frame)
		i_frame = 0;
	i = 0;
	while (i < map->count_monster)
	{
		pos = map->pos_monster[i];
		col = IMG_WIDTH * (pos % map->col);
		row = IMG_WIDTH * (pos / map->col);
		mlx_put_image_to_window(mlx->mlx_id, mlx->window, img->monster[i_frame], col, row);
		i++;
	}
	i_frame = (i_frame + 1) % FRAME_COUNT_MONSTER;
}

void	render_animation_player(t_mlx *mlx, t_img *img, t_map *map)
{
	static size_t	i_frame;
	size_t			pos;
	size_t			col;
	size_t			row;

	if (!i_frame)
		i_frame = 0;
	pos = *map->pos_player;
	col = IMG_WIDTH * (pos % map->col);
	row = IMG_WIDTH * (pos / map->col);
	mlx_put_image_to_window(mlx->mlx_id, mlx->window, img->player[i_frame], col, row);
	i_frame = (i_frame + 1) % FRAME_COUNT_PLAYER;
}

int	main_loop_animation(t_mlx *mlx)
{
	static size_t	frame_count;

	if (!frame_count)
		frame_count = 0;
	if (frame_count > ANIM_SPEED)
	{
		render_animation_monsters(mlx, mlx->img, mlx->map);
		render_animation_player(mlx, mlx->img, mlx->map);
		if (mlx->map->health_player <= 0)
			anim_game_over(mlx);
		frame_count = 0;
	}
	frame_count++;
	return (0);
}
