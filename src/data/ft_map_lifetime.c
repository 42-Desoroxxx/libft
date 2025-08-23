/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_lifetime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 03:46:13 by llage             #+#    #+#             */
/*   Updated: 2025/08/23 03:46:13 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_data.h>

t_map	map_bzero(void)
{
	return ((t_map){
		.entries = NULL,
		.size = 0,
	});
}

void	map_free(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->size)
	{
		free(map->entries[i].key);
		free(map->entries[i].value);
		i++;
	}
	free(map->entries);
	*map = map_bzero();
}
