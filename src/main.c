/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:33:49 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/01 07:00:24 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static short	map_validate_ext(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4)
		return (1);
	if (ft_strncmp(path + len - 4, ".ber", len) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_msg_put_exrror("Usage: ./so_long [path to map.ber]");
	if (map_validate_ext(argv[1]))
		ft_msg_put_exrror("Arg: Please use a .ber file");
	so_long(argv[1]);
	return (0);
}
