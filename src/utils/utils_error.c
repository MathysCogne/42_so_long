/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 06:34:55 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/01 07:00:26 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_error(short error, t_mlx *mlx, t_map *map)
{
	free_struct_map(map);
	if (error == 0)
		return ;
	if (error == 1)
		ft_msg_put_exrror(ERROR_MSG_CHARAC);
	if (error == 2)
		ft_msg_put_exrror(ERROR_MSG_ITEM_START_END);
	if (error == 3)
		ft_msg_put_exrror(ERROR_MSG_MAP_RECTANGULAR);
	if (error == 4)
		ft_msg_put_exrror(ERROR_MSG_MAP_CLOSED_WALL);
	if (error == 5)
		ft_msg_put_exrror(ERROR_MSG_MAP_VALID_PATH);
	if (error == 6)
		ft_msg_put_exrror(ERROR_MSG_STRUCTURE);
	free_struct_img(mlx->img);
	free_struct_mlx(mlx);
	if (error == 7)
		ft_msg_put_exrror(ERROR_MSG_MLX_WIN);
	if (error == 8)
		ft_msg_put_exrror(ERROR_MSG_STRUCTURE_LOAD);
	if (error == 9)
		ft_msg_put_exrror(ERROR_MSG_MLX_LOOP);
	if (error == 10)
		ft_msg_put_exrror(ERROR_MSG_EXIT_USER);
}

void	ft_msg_put_exrror(char *msg_error)
{
	ft_putstr_fd("Error.\n", 0);
	ft_putstr_fd(msg_error, 0);
	ft_putstr_fd("\n", 0);
	// TODO ADD SORTIE PGRM PROPREMENT
	exit(EXIT_FAILURE);
}