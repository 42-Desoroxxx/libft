/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 06:49:12 by llage             #+#    #+#             */
/*   Updated: 2025/08/25 06:49:20 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_data.h>
#include <ft_printf.h>

void	map_print(const t_map *map)
{
	size_t	i;

	i = -1;
	while (++i < map->size)
		ft_printf("%s=%s\n", map->entries[i].key, map->entries[i].value);
}
