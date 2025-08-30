/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:05:52 by llage             #+#    #+#             */
/*   Updated: 2024/10/23 02:16:27 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

/**
 * Copies `n` bytes from memory area `src` to memory area `dest`.
 *
 * The memory areas may overlap;
 * the copy is performed in a way that ensures the original data in `src` is
 * preserved during the copy.
 *
 * @param dest A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param n The number of bytes to copy.
 * @return A pointer to the destination memory area `dest`.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_copy = src;
	unsigned char		*dest_copy;

	if (dest == NULL || src == NULL)
		return (dest);
	dest_copy = dest;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		dest_copy += n - 1;
		src_copy += n - 1;
		while (n-- > 0)
			*dest_copy-- = *src_copy--;
	}
	return (dest);
}
