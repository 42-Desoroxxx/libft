/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:59:38 by llage             #+#    #+#             */
/*   Updated: 2024/10/09 16:59:54 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

/**
 * Sets the first `n` bytes of the memory area pointed to by `s` with the
 * integer `c` (interpreted as an unsigned char).
 *
 * @param s A pointer to the memory area to be filled.
 * @param c The value to be set to each byte.
 * @param n The number of bytes to set to the value `c`.
 * @return A pointer to the memory area `s`.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_copy;

	s_copy = s;
	while (n--)
		*s_copy++ = c;
	return (s);
}
