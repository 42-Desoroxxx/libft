/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 02:10:52 by llage             #+#    #+#             */
/*   Updated: 2024/10/17 02:25:00 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

/**
 * Compares the first n bytes of two memory areas.
 *
 * @param s1 A pointer to the first memory area.
 * @param s2 A pointer to the second memory area.
 * @param n The number of bytes to compare.
 * @return An integer less than,
 *         equal to,
 *         or greater than zero if the first n bytes of s1 are found,
 *         respectively,
 *         to be less than,
 *         to match,
 *         or to be greater than the first n bytes of s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_copy = s1;
	const unsigned char	*s2_copy = s2;

	while (n--)
	{
		if (*s1_copy != *s2_copy)
			return (*s1_copy - *s2_copy);
		s1_copy++;
		s2_copy++;
	}
	return (0);
}
