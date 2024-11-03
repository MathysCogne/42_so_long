/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:56:52 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/03 18:35:54 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Displays a banner at the window.
** Player move count and item collected
*/
void	set_turn_banner(t_mlx *mlx)
{
	size_t	col;
	size_t	row;

	col = ((mlx->map->col - 1) / 2) * IMG_WIDTH;
	row = 0;
	mlx_put_image_to_window(mlx->mlx_id, mlx->window,
		mlx->img->ui_banner_turn[mlx->is_player_turn], col, row);
}

static void	put_a_digit_move(t_mlx *mlx, short digit, size_t pos)
{
	size_t	col;
	size_t	row;

	if (digit < 0 || digit > 9)
		return ;
	col = (((mlx->map->col - 1) / 2) + 3) * IMG_WIDTH;
	row = 0;
	if (pos == 1)
		mlx_put_image_to_window(mlx->mlx_id, mlx->window,
			mlx->img->ui_digits[digit], col + 34, row + 20);
	else if (pos == 2)
		mlx_put_image_to_window(mlx->mlx_id, mlx->window,
			mlx->img->ui_digits[digit], col + 44, row + 20);
	else if (pos == 3)
		mlx_put_image_to_window(mlx->mlx_id, mlx->window,
			mlx->img->ui_digits[digit], col + 54, row + 20);
}

void	draw_digit_move(t_mlx *mlx, size_t digit)
{
	size_t	col;
	char	*nb;

	nb = ft_itoa(digit);
	col = (((mlx->map->col - 1) / 2) + 3) * IMG_WIDTH;
	mlx_put_image_to_window(mlx->mlx_id, mlx->window, mlx->img->ui_digits[10],
		col, 0);
	put_a_digit_move(mlx, 0, 1);
	put_a_digit_move(mlx, 0, 2);
	if (ft_strlen(nb) == 1)
		put_a_digit_move(mlx, nb[0] - '0', 3);
	else if (ft_strlen(nb) == 2)
	{
		put_a_digit_move(mlx, nb[0] - '0', 2);
		put_a_digit_move(mlx, nb[1] - '0', 3);
	}
	else
	{
		put_a_digit_move(mlx, nb[0] - '0', 1);
		put_a_digit_move(mlx, nb[1] - '0', 2);
		put_a_digit_move(mlx, nb[2] - '0', 3);
	}
	free(nb);
}

static void	put_a_digit_item(t_mlx *mlx, short digit, size_t pos)
{
	size_t	col;
	size_t	row;

	if (digit < 0 || digit > 9)
		return ;
	col = (((mlx->map->col - 1) / 2) - 3) * IMG_WIDTH;
	row = 0;
	if (pos == 1)
		mlx_put_image_to_window(mlx->mlx_id, mlx->window,
			mlx->img->ui_digits[digit], col + 34, row + 20);
	else if (pos == 2)
		mlx_put_image_to_window(mlx->mlx_id, mlx->window,
			mlx->img->ui_digits[digit], col + 44, row + 20);
}

void	draw_digit_item(t_mlx *mlx, size_t digit)
{
	size_t	col;
	size_t	row;
	char	*nb;

	nb = ft_itoa(digit);
	col = (((mlx->map->col - 1) / 2) - 3) * IMG_WIDTH;
	row = 0;
	mlx_put_image_to_window(mlx->mlx_id, mlx->window,
		mlx->img->ui_item, col, row);
	put_a_digit_item(mlx, 0, 1);
	put_a_digit_item(mlx, 0, 2);
	if (ft_strlen(nb) == 1)
		put_a_digit_item(mlx, nb[0] - '0', 2);
	else if (ft_strlen(nb) == 2)
	{
		put_a_digit_item(mlx, nb[0] - '0', 1);
		put_a_digit_item(mlx, nb[1] - '0', 2);
	}
	free(nb);
}
