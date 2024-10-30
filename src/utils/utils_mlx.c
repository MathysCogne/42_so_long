/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:18:46 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/30 19:42:21 by mcogne--         ###   ########.fr       */
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
