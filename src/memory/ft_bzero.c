/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:26:23 by llage             #+#    #+#             */
/*   Updated: 2024/10/20 12:01:42 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

/**
 * Sets the first `n` bytes of the memory area pointed to by `s` to zero.
 *
 * @param s A pointer to the memory area to be zeroed.
 * @param n The number of bytes in the memory area to set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
