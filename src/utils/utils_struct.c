/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:21:28 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/30 20:12:30 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Initializes structures:
** Map dat / Mlx data / Textures 
** And Monsters (use only in game_move_monsters.c)
** Load textures digits UI (0 - 9)
*/
/******** DATA MAP *********/
t_map	*map_init_struct(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->txt = NULL;
	map->col = 0;
	map->row = 0;
	map->count_move = 0;
	map->collect_item = 0;
	map->health_player = 3;
	map->pos_player = NULL;
	map->pos_exit = NULL;
	map->pos_void = NULL;
	map->pos_wall = NULL;
	map->pos_item = NULL;
	map->pos_monster = NULL;
	map->count_start = 0;
	map->count_exit = 0;
	map->count_void = 0;
	map->count_wall = 0;
	map->count_item = 0;
	map->count_monster = 0;
	return (map);
}

/********* DATA MLX *********/
t_mlx	*ft_mlx_init_struct(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx_id = NULL;
	mlx->window = NULL;
	mlx->is_player_turn = 1;
	mlx->img = NULL;
	mlx->map = NULL;
	return (mlx);
}

/******* DATA TEXTURE *******/
t_img	*texture_init_struct(void)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->width = 0;
	img->height = 0;
	*img->player = NULL;
	img->player_dead = NULL;
	img->item = NULL;
	img->wall = NULL;
	img->exit_close = NULL;
	img->exit_open = NULL;
	*img->flat = NULL;
	*img->monster = NULL;
	*img->ui_health = NULL;
	*img->ui_digits = NULL;
	img->ui_item = NULL;
	*img->ui_banner_turn = NULL;
	return (img);
}

t_monster	*initialize_monsters(t_map *map)
{
	size_t		id;
	t_monster	*monsters;

	monsters = malloc(sizeof(t_monster) * map->count_monster);
	if (!monsters)
		return (NULL);
	id = 0;
	while (id < map->count_monster)
	{
		monsters[id].id = id;
		monsters[id].pos = map->pos_monster[id];
		monsters[id].col = monsters[id].pos % map->col;
		monsters[id].row = monsters[id].pos / map->col;
		id++;
	}
	return (monsters);
}

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
