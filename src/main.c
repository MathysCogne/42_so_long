/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:33:49 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/27 02:16:39 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_put_exrror("Usage: ./so_long [path to map.ber]");
	if (!map_validate_ext(argv[1]))
		ft_put_exrror("Arg: Please use a .ber file");
	so_long(argv[1]);
	return (0);
}
