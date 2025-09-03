/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_byte_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:01:15 by llage             #+#    #+#             */
/*   Updated: 2025/09/03 19:01:15 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_memory.h>

char	*ft_byte_to_str(const uint8_t status)
{
	static char	str[4];

	ft_bzero(str, 4);
	if (status < 10)
		str[0] = status + '0';
	else if (status < 100)
	{
		str[0] = (status / 10) + '0';
		str[1] = (status % 10) + '0';
	}
	else
	{
		str[0] = (status / 100) + '0';
		str[1] = ((status % 100) / 10) + '0';
		str[2] = ((status % 100) % 10) + '0';
	}
	return (str);
}
