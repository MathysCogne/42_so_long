/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 06:05:57 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/03 20:38:12 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_struct_mlx(t_mlx *mlx)
{
	free(mlx);
}

void	free_struct_map(t_map *map)
{
	free(map->txt);
	if (map->pos_player)
		free(map->pos_player);
	if (map->pos_exit)
		free(map->pos_exit);
	if (map->pos_void)
		free(map->pos_void);
	if (map->pos_wall)
		free(map->pos_wall);
	if (map->pos_item)
		free(map->pos_item);
	if (map->pos_monster)
		free(map->pos_monster);
	free(map);
}

static void	free_img(t_mlx *mlx, t_img *img)
{
	size_t	i;

	i = 0;
	while (i < 10)
	{
		(void)mlx;
		(void)img;
		// if (i <= 3)
		// 	mlx_destroy_image(mlx->mlx_id, img->ui_health[i]);
		// if (i <= 4)
		// {
		// 	mlx_destroy_image(mlx->mlx_id, img->flat[i]);
		// 	mlx_destroy_image(mlx->mlx_id, img->monster[i]);
		// }
		// if (i <= 6)
		// 	mlx_destroy_image(mlx->mlx_id, img->player[i]);
		// if (i <= 8)
		// 	mlx_destroy_image(mlx->mlx_id, img->wall_ext[i]);
		// if (i <= 10)
		// 	mlx_destroy_image(mlx->mlx_id, img->ui_digits[i]);
		i++;
	}
}

void	free_struct_img(t_mlx *mlx, t_img *img)
{
	// mlx_destroy_image(mlx->mlx_id, img->player_dead);
	// img->player_dead = NULL;
	// mlx_destroy_image(mlx->mlx_id, img->item);
	// img->item = NULL;
	// mlx_destroy_image(mlx->mlx_id, img->wall);
	// img->wall = NULL;
	// mlx_destroy_image(mlx->mlx_id, img->exit_close);
	// img->exit_close = NULL;
	// mlx_destroy_image(mlx->mlx_id, img->exit_open);
	// img->exit_open = NULL;
	// mlx_destroy_image(mlx->mlx_id, img->ui_item);
	// img->ui_item = NULL;
	// mlx_destroy_image(mlx->mlx_id, img->ui_banner_turn[0]);
	// img->ui_banner_turn[0] = NULL;
	// mlx_destroy_image(mlx->mlx_id, img->ui_banner_turn[1]);
	// img->ui_banner_turn[1] = NULL;
	free_img(mlx, img);
	free(img);
}