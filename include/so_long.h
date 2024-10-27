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

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

/************** SO_LONG **************/
short	so_long(char *path);

/**************** MAP ****************/
typedef struct	s_map
{
	size_t		col;
	size_t		row;
	size_t		*pos_start;
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
short	map_verif(char *map_txt, t_map *map);
short	map_valid_path(t_map *map);

/**************** MLX ****************/
typedef struct s_mlx
{
	void	*mlx_id;
	void	*window;
}			t_mlx;

short	ft_mlx_start(t_mlx **map);

/************* TEXTURES **************/
typedef struct s_texture
{
	int		*img_width;
	int		*img_height;
	void	*player_img;
	void	*wall_img;
	void	*void_img;
	void	*item_img;
}			t_texture;

/*************** UTILS ***************/
void	ft_put_exrror(char *msg_error);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif
