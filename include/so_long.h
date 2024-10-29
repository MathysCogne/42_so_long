#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"

# include <stdlib.h>
# include <fcntl.h>

/*************** MACRO ***************/
# define START		'P'
# define EXIT		'E'
# define VOID		'0'
# define WALL		'1'
# define ITEM		'C'
# define MONSTER	'M'

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_S			115
# define KEY_A			97
# define KEY_D			100
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363

/*** IMG ***/
# define IMG_PLAYER		"./sprites/player/player_flat.xpm"
# define IMG_P_DEAD		"./sprites/player/player_dead.xpm"
# define IMG_P_START	"./sprites/player/player_start.xpm"

# define IMG_MONSTER_0	"./sprites/monsters/monster_0.xpm"
# define IMG_MONSTER_1	"./sprites/monsters/monster_1.xpm"
# define IMG_MONSTER_2	"./sprites/monsters/monster_2.xpm"
# define IMG_MONSTER_3	"./sprites/monsters/monster_3.xpm"
# define IMG_MONSTER_4	"./sprites/monsters/monster_4.xpm"

# define IMG_ITEM		"./sprites/item.xpm"

# define IMG_WALL		"./sprites/wall.xpm"

# define IMG_EXIT		"./sprites/exit/end_close.xpm"
# define IMG_EXIT_OPEN	"./sprites/exit/end_open.xpm"

# define IMG_FLAT		"./sprites/flat/flat_0.xpm"
# define IMG_FLAT_1		"./sprites/flat/flat_1.xpm"
# define IMG_FLAT_2		"./sprites/flat/flat_2.xpm"
# define IMG_FLAT_3		"./sprites/flat/flat_3.xpm"
# define IMG_FLAT_4		"./sprites/flat/flat_4.xpm"

# define IMG_WIDTH		49

# define ANIM_SPEED		6000
# define FRAME_COUNT	5

# define WIN_WIDTH		1950
# define WIN_HEIGHT		975

/************** SO_LONG **************/
short	so_long(char *path);

/**************** MAP ****************/
typedef struct	s_map
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

short	map_validate_ext(char *path);
short	map_init(char *path, t_map **map);
short	map_verif(t_map *map);
short	map_valid_path(t_map *map);

/************* TEXTURES **************/
typedef struct s_img
{
	int		width;
	int		height;

	void	*player;
	void	*player_start;
	void	*player_dead;

	void	*item;
	void	*wall;

	void	*exit_close;
	void	*exit_open;

	void	*flat[5];
	void	*monster[5];
	size_t	monster_frame_index;
}			t_img;

/**************** MLX ****************/
typedef struct s_mlx
{
	void	*mlx_id;
	void	*window;
	t_map	*map;
	t_img	*img;
}			t_mlx;

short	ft_mlx_start(t_map **map, t_mlx **mlx_data, t_img **img_data);
short	ft_mlx_setup_hook(t_mlx *mlx);
int		ft_mlx_close_window(t_mlx *mlx);
int		ft_mlx_keypress(int	keycode, t_mlx *mlx);
short	ft_mlx_render(t_map *map, t_mlx *mlx, t_img *img);
short	ft_mlx_load_texture(t_mlx *mlx, t_img *img);
short	ft_mlx_put_image_to_window(t_mlx *mlx, void *ptr_img, size_t pos);
int		main_loop_animation(t_mlx *mlx);
void	render_animation_monsters(t_mlx *mlx, t_img *img, t_map *map);


short	map_init_render(t_map *map, t_mlx *mlx, t_img *img); // TOTO MOVE TO MAP
short	map_randomize_patern_void(t_mlx *mlx, t_img *img, size_t col, size_t row);

/*************** GAME ****************/
typedef struct	s_monster {
	size_t	id;
	size_t	pos;
	size_t	col;
	size_t	row;
} 		t_monster;

short	move_player(t_mlx *mlx, int to_row, int to_col);
short	move_monsters_ia(t_mlx *mlx, t_map *map);
short	is_wall_pos_or_door_close(t_map *map, size_t col, size_t row);
short	is_item_pos(t_map *map, size_t pos);
short	is_door_open_pos(t_map *map, size_t pos);

/*************** UTILS ***************/
void	ft_put_exrror(char *msg_error);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
size_t	random_index_0_5(size_t index);
int		ft_abs(int nb);

/************ UTILS STRUCT ***********/
t_map	*map_init_struct(void);
t_mlx	*ft_mlx_init_struct(void);
t_img	*texture_init_struct(void);

#endif
