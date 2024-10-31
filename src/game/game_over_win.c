/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:32:40 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/31 14:31:09 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_game_over(t_mlx *mlx)
{
	static size_t	i;
	static size_t	j;
	size_t			inner_col;
	size_t			inner_row;

	inner_col = mlx->map->col - 2;
	inner_row = mlx->map->row - 2;
	if (!i)
	{
		i = mlx->map->col + 1;
		j = (mlx->map->row - 1) * mlx->map->col - 2;
	}
	if (i >= ((inner_row * mlx->map->col) - inner_col))
		return ;
	ft_mlx_put_image_to_window(mlx, mlx->img->wall_ext[8], i);
	ft_mlx_put_image_to_window(mlx, mlx->img->wall_ext[8], j);
	i++;
	if (i % mlx->map->col == mlx->map->col - 1)
		i += 2;
	j--;
	if (j % mlx->map->col == 0)
		j -= 2;
}

void	game_over(t_mlx *mlx)
{
	ft_mlx_put_image_to_window(mlx, mlx->img->player_dead,
		*mlx->map->pos_player);
	*mlx->map->pos_player = mlx->map->col * mlx->map->row;
	ft_printf("\nGAME OVER !\n");
}

void	game_win(t_mlx *mlx)
{
	(void)mlx;
	ft_printf("\nWIN GAME GG !\n");
}
