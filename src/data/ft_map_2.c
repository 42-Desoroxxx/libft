/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:53:52 by llage             #+#    #+#             */
/*   Updated: 2025/08/23 02:36:04 by llage            ###   ########.fr       */
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
		if (map->entries[i].key != NULL)
			ft_printf("%s=%s\n", map->entries[i].key, map->entries[i].value);
		i++;
	}
}
