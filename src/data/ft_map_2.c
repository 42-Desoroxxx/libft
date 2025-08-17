/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logname <logname@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 05:00:38 by logname           #+#    #+#             */
/*   Updated: 2025/08/17 05:07:32 by logname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_data.h>
#include <libft.h>
#include <ft_printf.h>

void	map_print(const t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->size)
	{
		ft_printf("%s=%s\n", map->entries[i].key, map->entries[i].value);
		i++;
	}
}
