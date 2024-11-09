/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:21:05 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/09 20:35:59 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Renders the animation for
** - Monsters
** - Player
** Main loop for amimation p & m and manage time turn for monsters 
** when mlx->is_player_turn = 1)
*/
void	render_animation_monsters(t_mlx *mlx, t_img *img, t_map *map)
{
	static size_t	i_frame;
	size_t			i;
	size_t			pos;

	if (!i_frame)
		i_frame = 0;
	i = 0;
	while (i < map->count_monster)
	{
		pos = map->pos_monster[i];
		ft_mlx_put_image_to_window(mlx, img->monster[i_frame], pos);
		i++;
	}
	i_frame = (i_frame + 1) % FRAME_COUNT_MONSTER;
}

static void	render_animation_player(t_mlx *mlx, t_img *img, t_map *map)
{
	static size_t	i_frame;
	size_t			pos;

	if (!i_frame)
		i_frame = 0;
	pos = *map->pos_player;
	ft_mlx_put_image_to_window(mlx, img->player[i_frame], pos);
	i_frame = (i_frame + 1) % FRAME_COUNT_PLAYER;
}

static void	event_anim_animspeed(t_mlx *mlx)
{
	render_animation_monsters(mlx, mlx->img, mlx->map);
	render_animation_player(mlx, mlx->img, mlx->map);
	if (mlx->map->health_player <= 0)
	{
		ft_mlx_put_image_to_window(mlx, mlx->img->player_dead,
			*mlx->map->pos_player);
		*mlx->map->pos_player = mlx->map->col * mlx->map->row;
		anim_game_over(mlx);
	}
}

int	main_loop_animation(t_mlx *mlx)
{
	static size_t	frame_count;
	static size_t	frame_count_ia_monster;

	if (!frame_count)
	{
		frame_count = 0;
		frame_count_ia_monster = 0;
	}
	if (frame_count > ANIM_SPEED)
	{
		event_anim_animspeed(mlx);
		frame_count = 0;
	}
	if (frame_count_ia_monster > ANIM_MOVE_MONSTERS)
	{
		if (!mlx->is_player_turn)
			move_monsters_ia(mlx, mlx->map);
		frame_count_ia_monster = 0;
	}
	frame_count++;
	frame_count_ia_monster++;
	return (0);
}
