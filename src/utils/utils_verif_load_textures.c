/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_verif_load_textures.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 06:11:00 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/09 20:21:28 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static short	verif_load_texture_map(t_img *img)
{
	size_t	i;

	i = 0;
	while (i <= 4)
	{
		if (!img->flat[i])
			return (1);
		i++;
	}
	i = 0;
	while (i <= 8)
	{
		if (!img->wall_ext[i])
			return (1);
		i++;
	}
	if (!img->player_dead || !img->item || !img->wall
			|| !img->exit_close || !img->exit_open)
		return (1);
	return (0);
}

static short	verif_load_texture_player_monsters(t_img *img)
{
	size_t	i;

	i = 0;
	while (i <= 4)
	{
		if (!img->monster[i])
			return (1);
		i++;
	}
	i = 0;
	while (i <= 6)
	{
		if (!img->player[i])
			return (1);
		i++;
	}
	return (0);
}

static short	verif_load_texture_ui(t_img *img)
{
	size_t	i;

	i = 0;
	while (i <= 3)
	{
		if (!img->ui_health[i])
			return (1);
		i++;
	}
	i = 0;
	while (i <= 10)
	{
		if (!img->ui_digits[i])
			return (1);
		i++;
	}
	if (!img->ui_item || !img->ui_banner_turn[0]
			|| !img->ui_banner_turn[1])
		return (1);
	return (0);
}

short	verif_load_texture(t_mlx *mlx)
{
	if (!mlx || !mlx->img)
		return (1);
	if (verif_load_texture_map(mlx->img))
		return (1);
	if (verif_load_texture_player_monsters(mlx->img))
		return (1);
	if (verif_load_texture_ui(mlx->img))
		return (1);
	return (0);
}