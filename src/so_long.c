/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:51:25 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/27 18:33:56 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	so_long(char *path)
{
	t_map	*map;
	t_mlx	*data;

	if (!map_init(path, &map))
		ft_put_exrror("Error loading map");
	if (!ft_mlx_start(&data))
		ft_put_exrror("Error loading window");
	return (0);
}