/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:00:18 by llage             #+#    #+#             */
/*   Updated: 2025/08/30 18:00:12 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

/**
 * Searches for the first occurrence of the integer `c`
 * (interpreted as an unsigned char) in the first `n` bytes of the memory area
 * pointed to by `s`.
 *
 * @param s A pointer to the memory area to search within.
 * @param c The character to search for, interpreted as an unsigned char.
 * @param n The number of bytes to search in the memory area.
 * @return A pointer to the first occurrence of the character `c` in the
 *         memory area,
 *         or NULL if the character is not found within the first `n` bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_copy;

	s_copy = s;
	while (n--)
	{
		if (*s_copy == (unsigned char) c)
			return ((void *) s_copy);
		s_copy++;
	}
	return (NULL);
}
