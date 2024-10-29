/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:32:40 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/30 00:12:07 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_game_over(t_mlx *mlx)
{
	static size_t	i;
	static size_t	j;

	if (!i)
	{
		i = mlx->map->col;
		j = mlx->map->col * (mlx->map->row - 1);
	}
	if (i == (mlx->map->col * (mlx->map->row )) / 2)
		return ;
	ft_mlx_put_image_to_window(mlx, mlx->img->wall, i);
	ft_mlx_put_image_to_window(mlx, mlx->img->wall, j);
	i++;
	--j;
	ft_printf("UN MUR ici %d !\n", i);
}

void	game_over(t_mlx *mlx)
{
	(void)mlx;
	ft_printf("\nGAME OVER !\n");
}

void	game_win(t_mlx *mlx)
{
	(void)mlx;
	ft_printf("\nWIN GAME GG !\n");
}