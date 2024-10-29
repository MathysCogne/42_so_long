/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:34:15 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/29 03:28:52 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

size_t	generate_random_nb(size_t index)
{
	size_t	seed;

	seed = index;
	seed = seed * 1103515245 + 12345;
	return ((seed / 655365) % 32768);
}

size_t	random_index_0_5(size_t index)
{
	size_t	random_nb;
	index *= 1103515245;
	index /= 4;
	random_nb = generate_random_nb(index) % 100;
	if (random_nb < 1)
		return (2);
	if (random_nb < 2)
		return (3);
	if (random_nb < 84)
		return (0);
	if (random_nb < 90)
		return (1);
	if (random_nb < 97)
		return (2);
	if (random_nb < 99)
		return (3);
	else
		return (4);
}

void	ft_put_exrror(char *msg_error)
{
	ft_putstr_fd("Error.\n", 0);
	ft_putstr_fd(msg_error, 0);
	ft_putstr_fd("\n", 0);
	// TODO ADD SORTIE PGRM PROPREMENT
	exit(EXIT_FAILURE);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	ft_memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}
