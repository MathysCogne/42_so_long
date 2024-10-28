/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:21:28 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/28 05:52:08 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/******** DATA MAP *********/
t_map	*map_init_struct(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->txt = NULL;
	map->col = 0;
	map->row = 0;
	map->pos_player = NULL;
	map->pos_exit = NULL;
	map->pos_void = NULL;
	map->pos_wall = NULL;
	map->pos_item = NULL;
	map->pos_monster = NULL;
	map->count_start = 0;
	map->count_exit = 0;
	map->count_void = 0;
	map->count_wall = 0;
	map->count_item = 0;
	map->count_monster = 0;
	return (map);
}

/********* DATA MLX *********/
t_mlx	*ft_mlx_init_struct(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx_id = NULL;
	mlx->window = NULL;
	mlx->img = NULL;
	mlx->map = NULL;
	return (mlx);
}

/******* DATA TEXTURE *******/
t_img	*texture_init_struct(void)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->width = 0;
	img->height = 0;
	img->player = NULL;
	img->start = NULL;
	img->exit = NULL;
	img->i_void = NULL;
	img->wall = NULL;
	img->item = NULL;
	return (img);
}
