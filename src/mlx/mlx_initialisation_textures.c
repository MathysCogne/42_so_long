/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialisation_textures.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:25:58 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/29 01:17:58 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	ft_mlx_put_image_to_window(t_mlx *mlx, void *ptr_img, size_t pos)
{
	size_t	col;
	size_t	row;

	col = IMG_WIDTH * (pos % mlx->map->col);
	row = IMG_WIDTH * (pos / mlx->map->col);
	mlx_put_image_to_window(mlx->mlx_id, mlx->window, ptr_img, col, row);
	return (1);
}

static short	ft_mlx_load_texture_flat(t_mlx *mlx, t_img *img)
{
	img->flat[0] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_FLAT, &img->width, &img->height);
	img->flat[1] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_FLAT_1, &img->width, &img->height);
	img->flat[2] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_FLAT_2, &img->width, &img->height);
	img->flat[3] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_FLAT_3, &img->width, &img->height);
	img->flat[4] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_FLAT_4, &img->width, &img->height);
	return (1);
}

static short	ft_mlx_load_texture_monsters(t_mlx *mlx, t_img *img)
{
	img->monster[0] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_MONSTER_0, &img->width, &img->height);
	img->monster[1] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_MONSTER_1, &img->width, &img->height);
	img->monster[2] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_MONSTER_2, &img->width, &img->height);
	img->monster[3] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_MONSTER_3, &img->width, &img->height);
	img->monster[4] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_MONSTER_4, &img->width, &img->height);
	img->monster_frame_index = 0;
	mlx->img = img;
	return (1);
}

short	ft_mlx_load_texture(t_mlx *mlx, t_img *img)
{
	img->player = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_PLAYER, &img->width, &img->height);
	img->player_dead = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_P_DEAD, &img->width, &img->height);
	img->player_start = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_P_START, &img->width, &img->height);

	img->item = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_ITEM, &img->width, &img->height);
	img->wall = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_WALL, &img->width, &img->height);

	img->exit_close = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_EXIT, &img->width, &img->height);
	img->exit_open = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_EXIT_OPEN, &img->width, &img->height);
	ft_mlx_load_texture_flat(mlx, img);
	ft_mlx_load_texture_monsters(mlx, img);
	return (1);
}