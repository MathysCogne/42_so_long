/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:24:54 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/28 23:55:27 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	ft_mlx_render(t_map *map, t_mlx *mlx, t_img *img)
{
	map_init_render(map, mlx, img);
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
	if (!ft_mlx_new_win(*mlx, (*mlx)->map->col * IMG_WIDTH, (*mlx)->map->row * IMG_WIDTH))
		return (0);
	if (!ft_mlx_load_texture(*mlx, (*mlx)->img))
		return (0);
	if (!ft_mlx_render(*map, *mlx, (*mlx)->img))
		return (0);
	return (1);
}
