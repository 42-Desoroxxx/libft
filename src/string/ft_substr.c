/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 07:14:47 by llage             #+#    #+#             */
/*   Updated: 2025/08/13 01:10:33 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_memory.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char const	*sub_start;
	size_t		sub_len;

	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	sub_start = s + start;
	sub_len = ft_strlen(sub_start);
	if (sub_len > len)
		sub_len = len;
	return (ft_strndup(sub_start, sub_len));
}
