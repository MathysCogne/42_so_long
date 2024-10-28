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

# define IMG_PLAYER		"./sprites/player_0.xpm"
# define IMG_MONSTER	"./sprites/monster_0.xpm"
# define IMG_ITEM		"./sprites/item_0.xpm"
# define IMG_EXIT		"./sprites/end_0.xpm"

# define IMG_VOID  		"./sprites/flat_0.xpm"
# define IMG_VOID_1		"./sprites/flat_1.xpm"
# define IMG_VOID_2		"./sprites/flat_2.xpm"

# define IMG_WALL		"./sprites/wall.xpm"

# define IMG_WIDTH		50

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
	void	*start;
	void	*exit;
	void	*i_void;
	void	*wall;
	void	*item;
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

/*************** GAME ****************/
short	move_player(t_mlx *mlx, int to_row, int to_col);

/*************** UTILS ***************/
void	ft_put_exrror(char *msg_error);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

/************ UTILS STRUCT ***********/
t_map	*map_init_struct(void);
t_mlx	*ft_mlx_init_struct(void);
t_img	*texture_init_struct(void);

#endif
