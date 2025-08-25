/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:53:52 by llage             #+#    #+#             */
/*   Updated: 2025/08/25 06:52:46 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_data.h>

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

static	t_map_entry	*get_entry(t_map *map, char *key)
{
	char			*cur_key;
	size_t			i;

	i = -1;
	while (++i < map->size)
	{
		cur_key = map->entries[i].key;
		if (!ft_strncmp(key, cur_key, ft_strlen(key) + 1))
			return (&map->entries[i]);
	}
	return (NULL);
}

/*
 * @return true if sucessful, false otherwise
 */
bool	map_set(t_map *map, char *key, char *value)
{
	size_t	i;

	i = -1;
	while (++i < map->size)
	{
		if (!ft_strncmp(key, map->entries[i].key, ft_strlen(key) + 1))
		{
			free(map->entries[i].value);
			map->entries[i].value = ft_strdup(value);
			return (true);
		}
	}
	grow(map);
	map->entries[i].key = ft_strdup(key);
	if (map->entries[i].key == NULL)
		return (false);
	if (value == NULL)
		return (true);
	map->entries[i].value = ft_strdup(value);
	if (map->entries[i].value == NULL)
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
	t_map_entry	*temp;
	size_t		i;
	size_t		j;

	temp = get_entry(map, key);
	if (temp == NULL)
		return (true);
	free(temp->key);
	temp->key = NULL;
	free(temp->value);
	temp->value = NULL;
	temp = ft_calloc(map->size - 1, sizeof(t_map_entry));
	if (temp == NULL)
		return (false);
	i = -1;
	j = 0;
	while (++i < map->size)
		if (map->entries[i].key != NULL)
			temp[j++] = map->entries[i];
	free(map->entries);
	map->entries = temp;
	map->size--;
	return (true);
}
