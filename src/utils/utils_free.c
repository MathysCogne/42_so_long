/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 06:05:57 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/01 07:01:36 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_struct_mlx(t_mlx *mlx)
{
	free(mlx);
}

void	free_struct_map(t_map *map)
{
	free(map);
}

void	free_struct_img(t_img *img)
{
	free(img);
}