/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 05:45:17 by llage             #+#    #+#             */
/*   Updated: 2025/08/30 18:12:53 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

/**
 * Allocates memory for an array of `nmemb` elements of `size` bytes each
 * and initializes all bytes to zero.
 *
 * @param nmemb The number of elements to allocate memory for.
 * @param size The size of each element in bytes.
 * @return A pointer to the allocated memory if successful, NULL otherwise.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	const size_t	total_size = nmemb * size;
	void			*result;

	if (nmemb > 0 && size > 0 && (total_size / size) != nmemb)
		return (NULL);
	result = malloc(total_size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, total_size);
	return (result);
}
