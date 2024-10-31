#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"

# include "path_textures.h"
# include "struct.h"

/*************** MACRO ***************/
/*** MAP ***/
# define START		'P'
# define EXIT		'E'
# define VOID		'0'
# define WALL		'1'
# define ITEM		'C'
# define MONSTER	'M'

/*** KEY ***/
# define KEY_ESC		65307
# define KEY_W			119
# define KEY_S			115
# define KEY_A			97
# define KEY_D			100
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_ENTER		65293
# define KEY_SPACE		32

/*** IMG PARAM ***/
# define IMG_WIDTH				49
# define IMG_WIDTH_HEALTH		98

# define ANIM_SPEED				6000
# define ANIM_MOVE_MONSTERS		12000

# define FRAME_COUNT_MONSTER	5
# define FRAME_COUNT_PLAYER		7

/************** SO_LONG **************/
short	so_long(char *path);

/**************** MAP ****************/
short	map_validate_ext(char *path);
short	map_init(char *path, t_map **map);
short	map_verif(t_map *map);
short	map_valid_path(t_map *map);

/**************** MLX ****************/
short	ft_mlx_start(t_map **map, t_mlx **mlx_data, t_img **img_data);
short	ft_mlx_setup_hook(t_mlx *mlx);
int		ft_mlx_close_window(t_mlx *mlx);
int		ft_mlx_keypress(int	keycode, t_mlx *mlx);
short	ft_mlx_render(t_map *map, t_mlx *mlx, t_img *img);
short	ft_mlx_load_texture(t_mlx *mlx, t_img *img);
short	ft_mlx_load_texture_digits_ui(t_mlx *mlx, t_img *img); // ? In utils_struct, thank's norm..
short	ft_mlx_load_texture_wall_ext(t_mlx *mlx, t_img *img); // ? In utils_struct, thank's norm..
short	ft_mlx_put_image_to_window(t_mlx *mlx, void *ptr_img, size_t pos);
int		main_loop_animation(t_mlx *mlx);
void	render_animation_monsters(t_mlx *mlx, t_img *img, t_map *map);


short	map_init_render(t_map *map, t_mlx *mlx, t_img *img); // TODO MOVE TO MAP
short	map_randomize_patern_void(t_mlx *mlx, t_img *img, size_t col, size_t row);

/*************** GAME ****************/
short	move_player(t_mlx *mlx, int to_row, int to_col);
short	move_monsters_ia(t_mlx *mlx, t_map *map);
short	is_wall_pos_or_door_close(t_map *map, size_t col, size_t row);
short	is_item_pos(t_map *map, size_t pos);
short	is_door_open_pos(t_map *map, size_t pos);
short	is_monster_pos(t_map *map, size_t pos);
short	attack_to_player(t_mlx *mlx, t_map *map);
void	game_over(t_mlx *mlx);
short	draw_health(t_mlx *mlx, t_map *map, t_img *img);
void	draw_digit_move(t_mlx *mlx, size_t digit);
void	draw_digit_item(t_mlx *mlx, size_t digit);
void	game_win(t_mlx *mlx);
void	anim_game_over(t_mlx *mlx);
void	set_turn_banner(t_mlx *mlx);
void	follow_player(t_mlx *mlx, int p_col, int p_row, t_monster *monster);

/*************** UTILS ***************/
void	ft_put_exrror(char *msg_error);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
size_t	random_index_0_5(size_t index);
int		ft_abs(int nb);

/************ UTILS STRUCT ***********/
t_map		*map_init_struct(void);
t_mlx		*ft_mlx_init_struct(void);
t_img		*texture_init_struct(void);
t_monster	*initialize_monsters(t_map *map);

#endif