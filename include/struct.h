/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:44:17 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/09 20:45:46 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdlib.h>

typedef struct s_map
{
	char		*txt;
	size_t		col;
	size_t		row;
	size_t		count_move;
	size_t		collect_item;
	size_t		health_player;
	size_t		*pos_player;
	size_t		*pos_exit;
	size_t		*pos_void;
	size_t		*pos_wall;
	size_t		*pos_item;
	size_t		*pos_monster;
	size_t		count_start;
	size_t		count_exit;
	size_t		count_void;
	size_t		count_wall;
	size_t		count_item;
	size_t		count_monster;
}				t_map;

typedef struct s_img
{
	int		width;
	int		height;
	void	*player[7];
	void	*player_dead;
	void	*item;
	void	*wall;
	void	*wall_ext[9];
	void	*exit_close;
	void	*exit_open;
	void	*flat[5];
	void	*monster[5];
	void	*ui_health[4];
	void	*ui_digits[11];
	void	*ui_item;
	void	*ui_banner_turn[2];
}			t_img;

typedef struct s_mlx
{
	void	*mlx_id;
	void	*window;
	size_t	is_player_turn;
	t_map	*map;
	t_img	*img;
}			t_mlx;

typedef struct s_monster
{
	size_t	id;
	size_t	pos;
	size_t	col;
	size_t	row;
}			t_monster;

#endif