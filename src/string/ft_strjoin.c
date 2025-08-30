/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:50:37 by llage             #+#    #+#             */
/*   Updated: 2025/08/26 06:01:54 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_memory.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	s1_length = ft_strlen(s1);
	const size_t	s2_length = ft_strlen(s2);
	const size_t	result_size = s2_length + s1_length + 1;
	char			*result;

	result = ft_calloc(result_size, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcat(result, s1, result_size);
	ft_strlcat(result, s2, result_size);
	return (result);
}
