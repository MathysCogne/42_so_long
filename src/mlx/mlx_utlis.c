/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:24:54 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/28 06:08:48 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	ft_mlx_put_image(t_map *map, t_mlx *mlx, t_img *img) // RENAME LOAD MAP
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
			mlx_put_image_to_window(mlx->mlx_id, mlx->window, img->i_void, col, row);
		if (map->txt[pos] == START)
			mlx_put_image_to_window(mlx->mlx_id, mlx->window, img->player, col, row);
		if (map->txt[pos] == EXIT)
			mlx_put_image_to_window(mlx->mlx_id, mlx->window, img->exit, col, row);
		pos++;
	}
	return (1);
}

short	ft_mlx_load_texture(t_mlx *mlx, t_img *img)
{
	img->player = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_PLAYER, &img->width, &img->height);
	img->wall = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_WALL, &img->width, &img->height);
	img->item = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_ITEM, &img->width, &img->height);
	img->i_void = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_VOID, &img->width, &img->height);
	img->exit = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_EXIT, &img->width, &img->height);
	if (!img->player || !img->wall || !img->i_void || !img->exit)
		return (0);
	mlx->img = img;
	return (1);
}

short	ft_mlx_render(t_map *map, t_mlx *mlx, t_img *img)
{
	ft_mlx_put_image(map, mlx, img);
	ft_mlx_setup_hook(mlx);
	mlx_loop(mlx->mlx_id);
	return (1);
}

short	ft_mlx_new_win(t_mlx *mlx, size_t width, size_t height)
{
	mlx->mlx_id = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_id, width, height, "So Long");
	return (1);
}

short	ft_mlx_start(t_map **map, t_mlx **mlx, t_img **img)
{
	*mlx = ft_mlx_init_struct();
	(*mlx)->img = texture_init_struct();
	(*mlx)->map = *map;
	if (!(*mlx) || !(*img))
		return (0);
	if (!ft_mlx_new_win(*mlx, ((*map)->col * IMG_WIDTH), ((*map)->row * IMG_WIDTH)))
		return (0);
	if (!ft_mlx_load_texture(*mlx, *img))
		return (0);
	if (!ft_mlx_render(*map, *mlx, *img))
		return (0);
	return (1);
}
