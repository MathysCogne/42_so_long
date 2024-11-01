/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:51:25 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/01 06:50:12 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	so_long(char *path)
{
	t_map	*map;
	t_mlx	*mlx;
	short	error_code;

	error_code = map_init(path, &map);
	if (error_code != 0)
		put_error(error_code, mlx, map);
	error_code = ft_mlx_start(&map, &mlx);
	if (error_code != 0)
		put_error(error_code, mlx, map);
	return (0);
}
