/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_textures_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:01:19 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/09 20:36:15 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Loading textures
** Digits UI, and wall ext map.
*/
short	ft_mlx_load_texture_digits_ui(t_mlx *mlx, t_img *img)
{
	img->ui_digits[0] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_DIGIT_0, &img->width, &img->width);
	img->ui_digits[1] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_DIGIT_1, &img->width, &img->width);
	img->ui_digits[2] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_DIGIT_2, &img->width, &img->width);
	img->ui_digits[3] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_DIGIT_3, &img->width, &img->width);
	img->ui_digits[4] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_DIGIT_4, &img->width, &img->width);
	img->ui_digits[5] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_DIGIT_5, &img->width, &img->width);
	img->ui_digits[6] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_DIGIT_6, &img->width, &img->width);
	img->ui_digits[7] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_DIGIT_7, &img->width, &img->width);
	img->ui_digits[8] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_DIGIT_8, &img->width, &img->width);
	img->ui_digits[9] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_DIGIT_9, &img->width, &img->width);
	img->ui_digits[10] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_DIGIT_10, &img->width, &img->width);
	return (1);
}

short	ft_mlx_load_texture_wall_ext(t_mlx *mlx, t_img *img)
{
	img->wall_ext[0] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_WALL_TOP, &img->width, &img->height);
	img->wall_ext[1] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_WALL_BOTTOM, &img->width, &img->height);
	img->wall_ext[2] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_WALL_RIGHT, &img->width, &img->height);
	img->wall_ext[3] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_WALL_LEFT, &img->width, &img->height);
	img->wall_ext[4] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_WALL_TOP_L, &img->width, &img->height);
	img->wall_ext[5] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_WALL_TOP_R, &img->width, &img->height);
	img->wall_ext[6] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_WALL_BOT_L, &img->width, &img->height);
	img->wall_ext[7] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_WALL_BOT_R, &img->width, &img->height);
	img->wall_ext[8] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_WALL_END, &img->width, &img->height);
	return (1);
}
