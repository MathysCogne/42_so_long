/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:24:54 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/09 20:28:42 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Initializes a new window MLX.
** Initializes a Loop MLX.
** Initializing map / resources / UI / .
*/
short	ft_mlx_render(t_map *map, t_mlx *mlx, t_img *img)
{
	map_init_render(map, mlx, img);
	set_turn_banner(mlx);
	draw_digit_item(mlx, mlx->map->collect_item);
	draw_digit_move(mlx, mlx->map->count_move);
	ft_mlx_setup_hook(mlx);
	mlx_loop(mlx->mlx_id);
	return (0);
}

short	ft_mlx_new_win(t_mlx *mlx, size_t width, size_t height)
{
	mlx->mlx_id = mlx_init();
	if (!mlx->mlx_id)
	{
		free_struct_map(mlx->map);
		free(mlx->img);
		free(mlx);
		exit(EXIT_FAILURE);	
	}
	mlx->window = mlx_new_window(mlx->mlx_id, (int)width, (int)height, "So_Long");
	if (!mlx->window)
		return (1);
	return (0);
}

short	ft_mlx_start(t_map **map, t_mlx **mlx)
{
	*mlx = ft_mlx_init_struct();
	(*mlx)->img = texture_init_struct();
	(*mlx)->map = *map;
	if (!(*mlx) || !(*mlx)->img)
		return (6);
	if (ft_mlx_new_win(*mlx, (*mlx)->map->col * IMG_WIDTH,
			(*mlx)->map->row * IMG_WIDTH))
		return (7);
	if (ft_mlx_load_texture(*mlx, (*mlx)->img))
		return (8);
	if (ft_mlx_render(*map, *mlx, (*mlx)->img))
		return (9);
	return (0);
}
