/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 03:35:41 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/27 04:57:03 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
** • La carte doit contenir 1 sortie, au moins 1 item et 1 position de départ.							CHECK !
** • La carte doit être de forme rectangulaire.															CHECK !
** • La carte doit être fermée en étant encadrée par des murs.											CHECK !
** • Vous devez vérifier s’il existe un chemin valide (i.e. qu’il est possible d’emprunter)			TODO
** • Si la map contient des doublons, vous devez afficher un message d’erreur.							CHECK !
** • Votre programme doit prendre en paramètre un fichier de carte se terminant par l’extension .ber	CHECK !
*/
short	map_contain_exit_start_item(t_map *map)
{
	if (map->count_exit != 1)
		return (0);
	if (map->count_start != 1)
		return (0);
	if (map->count_item == 0)
		return (0);
	return (1);
}

short	map_rectangular(t_map *map)
{
	if (map->col == map->row)
		return (0);
	return (1);
}

short	map_closed_wall(char *map_txt, t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->col)
	{
		if (map_txt[i] != WALL)
			return (0);
		if (map_txt[(map->col * (map->row - 1)) + i] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i < map->row)
	{
		if (map_txt[i * map->col] != WALL)
			return (0);
		if (map_txt[i * map->col + (map->col - 1)] != WALL)
			return (0);
		i++;
	}
	return (1);
}

short	map_verif(char *map_txt, t_map *map)
{
	if (!map_contain_exit_start_item(map))
	{
		ft_printf("ON SORT LAdddddddddddd");
		return (0);
	}
	if (!map_rectangular(map))
	{
		ft_printf("ON SORT LAdddd");
		return (0);
	}
	if (!map_closed_wall(map_txt, map))
	{
		ft_printf("ON SORT LA");
		return (0);
	}
	return (1);
}