/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 00:54:04 by llage             #+#    #+#             */
/*   Updated: 2025/08/13 01:08:51 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_memory.h>

char	*ft_strndup(const char *str, size_t n)
{
	size_t	length;
	char	*result;
	int		i;

	length = ft_strlen(str);
	if (length > n)
		length = n;
	result = ft_calloc(length + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (str[i] && n--)
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}
