/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:22:37 by llage             #+#    #+#             */
/*   Updated: 2025/08/30 17:29:26 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

/**
 * Safely frees a memory block and sets the pointer to NULL.
 *
 * @param ptr A pointer to a pointer to the memory block to be freed.
 *            If the pointer is NULL or the memory block being pointed to is
 *            NULL,
 *            the function does nothing.
 */
void	ft_safe_free(void **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}
