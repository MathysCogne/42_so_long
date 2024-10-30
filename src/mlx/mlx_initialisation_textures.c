/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialisation_textures.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:25:58 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/30 20:07:23 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Loading textures
** Player sprites, Monster sprites, UI elements, and textures map.
** UI digits elements in uyils_struc.c,, thank's Norm.. :( 
*/
static short	ft_mlx_load_texture_flat(t_mlx *mlx, t_img *img)
{
	img->flat[0] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_FLAT, &img->width, &img->height);
	img->flat[1] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_FLAT_1, &img->width, &img->height);
	img->flat[2] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_FLAT_2, &img->width, &img->height);
	img->flat[3] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_FLAT_3, &img->width, &img->height);
	img->flat[4] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_FLAT_4, &img->width, &img->height);
	return (1);
}

static short	ft_mlx_load_texture_monsters(t_mlx *mlx, t_img *img)
{
	img->monster[0] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_MONSTER_0, &img->width, &img->height);
	img->monster[1] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_MONSTER_1, &img->width, &img->height);
	img->monster[2] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_MONSTER_2, &img->width, &img->height);
	img->monster[3] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_MONSTER_3, &img->width, &img->height);
	img->monster[4] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_MONSTER_4, &img->width, &img->height);
	return (1);
}

short	ft_mlx_load_texture_player_anim(t_mlx *mlx, t_img *img)
{
	img->player[0] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_PLAYER_0, &img->width, &img->height);
	img->player[1] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_PLAYER_1, &img->width, &img->height);
	img->player[2] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_PLAYER_2, &img->width, &img->height);
	img->player[3] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_PLAYER_3, &img->width, &img->height);
	img->player[4] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_PLAYER_4, &img->width, &img->height);
	img->player[5] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_PLAYER_5, &img->width, &img->height);
	img->player[6] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_PLAYER_6, &img->width, &img->height);
	return (1);
}

static short	ft_mlx_load_texture_health_ui(t_mlx *mlx, t_img *img)
{
	img->ui_health[0] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_HEALTH_0, &img->width, &img->width);
	img->ui_health[1] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_HEALTH_1, &img->width, &img->height);
	img->ui_health[2] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_HEALTH_2, &img->width, &img->height);
	img->ui_health[3] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_HEALTH_3, &img->width, &img->height);
	img->ui_item = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_UI_ITEM, &img->width, &img->height);
	img->ui_banner_turn[0] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_MONSTER_BANNER, &img->width, &img->height);
	img->ui_banner_turn[1] = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_PLAYER_BANNER, &img->width, &img->height);
	mlx->img = img;
	return (1);
}

short	ft_mlx_load_texture(t_mlx *mlx, t_img *img)
{
	img->player_dead = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_P_DEAD, &img->width, &img->height);
	img->item = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_ITEM, &img->width, &img->height);
	img->wall = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_WALL, &img->width, &img->height);
	img->exit_close = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_EXIT, &img->width, &img->height);
	img->exit_open = mlx_xpm_file_to_image(mlx->mlx_id,
			IMG_EXIT_OPEN, &img->width, &img->height);
	ft_mlx_load_texture_flat(mlx, img);
	ft_mlx_load_texture_monsters(mlx, img);
	ft_mlx_load_texture_player_anim(mlx, img);
	ft_mlx_load_texture_digits_ui(mlx, img);
	ft_mlx_load_texture_health_ui(mlx, img);
	return (1);
}
