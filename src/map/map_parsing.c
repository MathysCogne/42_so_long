/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 02:12:11 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/30 19:41:40 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	new_pos = ft_realloc(*item, (*count) * sizeof(size_t),
			(*count + 1) * sizeof(size_t));
	if (!new_pos)
		return (0);
	*item = new_pos;
	(*item)[*count] = pos;
	(*count)++;
	return (1);
}

char	*map_revove_n(t_map *map)
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
	while (map->txt[i])
	{
		if (map->txt[i] != '\n')
		{
			tmp[j] = map->txt[i];
			j++;
		}
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

void	map_count_col_row(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->txt[i] && map->txt[i] != '\n')
	{
		map->col++;
		i++;
	}
	i = 0;
	while (map->txt[i])
	{
		if (map->txt[i] == '\n')
			map->row++;
		i++;
	}
	if (map->txt[i] != '\n')
		map->row++;
}

short	map_parse(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->txt[i])
	{
		if (map->txt[i] == START
			&& !map_add_pos(&map->pos_player, &map->count_start, i))
			return (0);
		if (map->txt[i] == EXIT
			&& !map_add_pos(&map->pos_exit, &map->count_exit, i))
			return (0);
		if (map->txt[i] == VOID
			&& !map_add_pos(&map->pos_void, &map->count_void, i))
			return (0);
		if (map->txt[i] == WALL
			&& !map_add_pos(&map->pos_wall, &map->count_wall, i))
			return (0);
		if (map->txt[i] == ITEM
			&& !map_add_pos(&map->pos_item, &map->count_item, i))
			return (0);
		if (map->txt[i] == MONSTER
			&& !map_add_pos(&map->pos_monster, &map->count_monster, i))
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

short	map_init(char *path, t_map **map)
{
	*map = map_init_struct();
	(*map)->txt = map_read(path);
	if (!(*map)->txt)
		return (0);
	if (!map)
		return (0);
	map_count_col_row(*map);
	(*map)->txt = map_revove_n(*map);
	if (!map_parse(*map))
		return (0);
	if (!map_verif(*map))
		return (0);
	return (1);
}
