/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:53:52 by llage             #+#    #+#             */
/*   Updated: 2025/08/23 03:45:04 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_data.h>
#include <ft_printf.h>

static bool	grow(t_map *map)
{
	t_map_entry	*temp;
	size_t		i;

	temp = ft_calloc(map->size + 1, sizeof(t_map_entry));
	if (temp == NULL)
		return (false);
	i = -1;
	while (++i < map->size)
	{
		temp[i].key = map->entries[i].key;
		temp[i].value = map->entries[i].value;
	}
	free(map->entries);
	map->entries = temp;
	map->size++;
	return (true);
}

/*
 * @return true if sucessful, false otherwise
 */
bool	map_set(t_map *map, char *key, char *value)
{
	char	*found_value;

	found_value = map_get(map, key);
	if (found_value != NULL)
	{
		free(found_value);
		found_value = ft_strdup(value);
		return (true);
	}
	grow(map);
	map->entries[map->size - 1].key = ft_strdup(key);
	if (map->entries[map->size - 1].key == NULL)
		return (false);
	if (value == NULL)
		return (true);
	map->entries[map->size - 1].value = ft_strdup(value);
	if (map->entries[map->size - 1].value == NULL)
		return (false);
	return (true);
}

char	*map_get(const t_map *map, char *key)
{
	char			*cur_key;
	size_t			i;

	i = -1;
	while (++i < map->size)
	{
		cur_key = map->entries[i].key;
		if (!ft_strncmp(key, cur_key, ft_strlen(key) + 1))
			return (map->entries[i].value);
	}
	return (NULL);
}

bool	map_unset(t_map *map, char *key)
{
	char			*cur_key;
	t_map_entry		*temp;
	size_t			i;

	if (map_get(map, key) == NULL)
		return (true);
	temp = ft_calloc(map->size - 1, sizeof(t_map_entry));
	if (temp == NULL)
		return (false);
	i = -1;
	while (++i < map->size)
	{
		cur_key = map->entries[i].key;
		if (ft_strncmp(key, cur_key, ft_strlen(key) + 1))
		{
			free(cur_key);
			continue ;
		}
		temp[i].key = cur_key;
	}
	free(map->entries);
	map->entries = temp;
	map->size--;
	return (true);
}

void	map_print(const t_map *map)
{
	size_t	i;

	i = -1;
	while (++i < map->size)
		ft_printf("%s=%s\n", map->entries[i].key, map->entries[i].value);
}
