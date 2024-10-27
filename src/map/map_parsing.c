/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 02:12:11 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/27 04:52:31 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map_init_struct(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->col = 0;
	map->row = 0;
	map->pos_start = NULL;
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

short	map_validate_ext(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4)
		return (0);
	if (ft_strncmp(path + len - 4, ".ber", len) == 0)
		return (1);
	return (0);
}

short	map_add_pos(size_t **item, size_t *count, size_t pos)
{
	size_t	*new_pos;

	new_pos = ft_realloc(*item, (*count) * sizeof(size_t), (*count + 1) * sizeof(size_t));
	if (!new_pos)
		return (0);
	*item = new_pos;
	(*item)[*count] = pos;
	(*count)++;
	return (1);
}

char	*map_revove_n(char *map_txt, t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*tmp;

	len = map->col * map->row;
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	i = 0;
	j = 0;
	while (map_txt[i])
	{
		if (map_txt[i] != '\n')
		{
			tmp[j] = map_txt[i];
			j++;
		}
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

void	map_count_col_row(char *map_txt, t_map *map)
{
	size_t i;

	i = 0;
	while (map_txt[i] && map_txt[i] != '\n')
	{
		map->col++;
		i++;
	}
	i = 0;
	while (map_txt[i])
	{
		if (map_txt[i] == '\n')
			map->row++;
		i++;
	}
	if (map_txt[i] != '\n')
		map->row++;
}

short	map_parse(char *map_txt, t_map *map)
{
	size_t	i;

	i = 0;
	while (map_txt[i])
	{
		if (map_txt[i] == START && !map_add_pos(&map->pos_start, &map->count_start, i))
			return (0);
		if (map_txt[i] == EXIT && !map_add_pos(&map->pos_exit, &map->count_exit, i))
			return (0);
		if (map_txt[i] == VOID && !map_add_pos(&map->pos_void, &map->count_void, i))
			return (0);
		if (map_txt[i] == WALL && !map_add_pos(&map->pos_wall, &map->count_wall, i))
			return (0);
		if (map_txt[i] == ITEM && !map_add_pos(&map->pos_item, &map->count_item, i))
			return (0);
		if (map_txt[i] == MONSTER && !map_add_pos(&map->pos_monster, &map->count_monster, i))
			return (0);
		i++;
	}
	return (1);
}

char	*map_read(char *path)
{
	int		fd;
	char	*map_txt;
	char	*line;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_put_exrror("Can't open file");
	map_txt = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(map_txt, line);
		free(map_txt);
		free(line);
		map_txt = tmp;
		line = get_next_line(fd);
	}
	close(fd);
	return (map_txt);
}

void print_map(t_map *map)
{
    ft_printf("Columns: %d\n", map->col);
    ft_printf("Rows: %d\n", map->row);

    // Affichage des positions
    ft_printf("Start: ");
    for (size_t i = 0; i < map->count_start; i++)
        ft_printf("%d ", map->pos_start[i]);
    ft_printf("\n");

    ft_printf("Exit: ");
    for (size_t i = 0; i < map->count_exit; i++)
        ft_printf("%d ", map->pos_exit[i]);
    ft_printf("\n");

    ft_printf("Void: ");
    for (size_t i = 0; i < map->count_void; i++)
        ft_printf("%d ", map->pos_void[i]);
    ft_printf("\n");

    ft_printf("Wall: ");
    for (size_t i = 0; i < map->count_wall; i++)
        ft_printf("%d ", map->pos_wall[i]);
    ft_printf("\n");

    ft_printf("Item: ");
    for (size_t i = 0; i < map->count_item; i++)
        ft_printf("%d ", map->pos_item[i]);
    ft_printf("\n");

    ft_printf("Monster: ");
    for (size_t i = 0; i < map->count_monster; i++)
        ft_printf("%d ", map->pos_monster[i]);
    ft_printf("\n");
}


short	map_init(char *path, t_map **map)
{
	char	*map_txt;

	map_txt = map_read(path);
	if (!map_txt)
		return (0);

	*map = map_init_struct();
	if (!map)
		return (0);
	map_count_col_row(map_txt, *map);
	map_txt = map_revove_n(map_txt, *map);
	if (!map_parse(map_txt, *map))
		return (0);

	/* DEBUG */
	ft_printf("%s\n\n", map_txt);
	print_map(*map);
	/******* */

	if (!map_verif(map_txt, *map))
		return(0);

	free(map_txt);
	return (1);
}
