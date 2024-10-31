/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:07:28 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/31 13:36:04 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Renders the game map
** Places walls, items, voids, the player, exit
** And a random background image.
*/
static void	map_draw_ext_wall(t_mlx *mlx, t_map *map, t_img *img)
{
	size_t	pos;
	size_t	bottom_row;
	size_t	last_col;

	bottom_row = map->col * (map->row - 1);
	last_col = map->col - 1;
	pos = 0;
	while (pos < map->col)
	{
		ft_mlx_put_image_to_window(mlx, img->wall_ext[0], pos);
		ft_mlx_put_image_to_window(mlx, img->wall_ext[1], bottom_row + pos);
		pos++;
	}
	pos = 0;
	while (pos < map->row)
	{
		ft_mlx_put_image_to_window(mlx, img->wall_ext[3], pos * map->col);
		ft_mlx_put_image_to_window(mlx, img->wall_ext[2], pos * map->col + last_col);
		pos++;
	}
	ft_mlx_put_image_to_window(mlx, img->wall_ext[4], 0);
	ft_mlx_put_image_to_window(mlx, img->wall_ext[5], last_col);
	ft_mlx_put_image_to_window(mlx, img->wall_ext[6], bottom_row);
	ft_mlx_put_image_to_window(mlx, img->wall_ext[7], bottom_row + last_col);
}

short	map_randomize_patern_void(t_mlx *mlx, t_img *img,
									size_t col, size_t row)
{
	size_t	random_i;

	random_i = random_index_0_5(col * row);
	mlx_put_image_to_window(mlx->mlx_id, mlx->window,
		img->flat[random_i], col, row);
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
			ft_mlx_put_image_to_window(mlx, img->wall, pos);
		if (map->txt[pos] == ITEM)
			ft_mlx_put_image_to_window(mlx, img->item, pos);
		if (map->txt[pos] == VOID)
			map_randomize_patern_void(mlx, img, col, row);
		if (map->txt[pos] == START)
			ft_mlx_put_image_to_window(mlx, img->player[0], pos);
		if (map->txt[pos] == EXIT)
			ft_mlx_put_image_to_window(mlx, img->exit_close, pos);
		pos++;
	}
	map_draw_ext_wall(mlx, map, img);
	return (1);
}
