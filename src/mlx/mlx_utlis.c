/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:24:54 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/27 18:54:21 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*ft_mlx_init_struct(void)
{
	t_mlx	*mlx_data;

	mlx_data = malloc(sizeof(t_map));
	if (!mlx_data)
		return (NULL);
	mlx_data->mlx_id = NULL;
	mlx_data->window = NULL;
	return (mlx_data);
}
t_texture	*ft_texture_init_struct(void)
{
	t_texture	*texture_data;

	texture_data = malloc(sizeof(t_texture));
	if (!texture_data)
		return (NULL);
	texture_data->img_width = 0;
	texture_data->img_height = 0;
	texture_data->player_img = NULL;
	texture_data->wall_img = NULL;
	return (texture_data);
}

short	ft_mlx_new_win(t_mlx *data)
{
	data->mlx_id = mlx_init();
	data->window = mlx_new_window(data->mlx_id, WIN_WIDTH, WIN_HEIGHT, "So Long");
	return (1);
}

short	ft_mlx_start(t_mlx **data)
{
	ft_mlx_new_win(*data);
	return (1);
}