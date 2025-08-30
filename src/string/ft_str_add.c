/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 05:24:10 by llage             #+#    #+#             */
/*   Updated: 2025/08/26 06:00:18 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_memory.h>

char	*ft_str_add(char const *dest, char const *src)
{
	const size_t	dest_length = ft_strlen(dest);
	const size_t	src_length = ft_strlen(src);
	const size_t	result_size = dest_length + src_length + 1;
	char			*result;

	result = ft_calloc(result_size, sizeof(char));
	if (result == NULL)
	{
		free((void *) dest);
		return (NULL);
	}
	ft_strlcat(result, dest, result_size);
	ft_strlcat(result, src, result_size);
	free((void *) dest);
	return (result);
}
