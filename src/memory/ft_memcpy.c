/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:06:24 by llage             #+#    #+#             */
/*   Updated: 2025/08/30 18:08:16 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

/**
 * Copies `n` bytes from memory area `src` to memory area `dest`.
 *
 * The memory areas mustn't overlap;
 *
 * @param dest A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param n The number of bytes to copy.
 * @return A pointer to the destination memory area `dest`.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_copy = src;
	unsigned char		*dest_copy;

	if (dest == NULL || src == NULL)
		return (dest);
	dest_copy = dest;
	while (n-- > 0)
	{
		*dest_copy = *src_copy;
		dest_copy++;
		src_copy++;
	}
	return (dest);
}
