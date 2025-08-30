/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:53:52 by llage             #+#    #+#             */
/*   Updated: 2025/08/26 05:27:47 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_data.h>
#include <ft_memory.h>

/*
 * @return true if successful, false otherwise
 */
static bool	grow(t_map *map)
{
	t_map_entry	*new_entries;
	size_t		i;

	new_entries = ft_calloc(map->size + 1, sizeof(t_map_entry));
	if (new_entries == NULL)
		return (false);
	i = -1;
	while (++i < map->size)
		new_entries[i] = map->entries[i];
	free(map->entries);
	map->entries = new_entries;
	map->size++;
	return (true);
}

/*
 * @return the entry if successful, NULL otherwise
 */
static	t_map_entry	*get_entry(const t_map *map, char *key)
{
	size_t	i;

	i = -1;
	while (++i < map->size)
		if (ft_str_equal(key, map->entries[i].key))
			return (&map->entries[i]);
	return (NULL);
}

/*
 * @return the value if successful, NULL otherwise
 */
char	*map_get(const t_map *map, char *key)
{
	const t_map_entry	*result = get_entry(map, key);

	if (result == NULL)
		return (NULL);
	return (result->value);
}

/*
 * @return true if successful, false otherwise
 */
bool	map_set(t_map *map, char *key, char *value)
{
	t_map_entry	*temp;

	temp = get_entry(map, key);
	if (temp != NULL)
	{
		free(temp->value);
		temp->value = ft_strdup(value);
		return (true);
	}
	grow(map);
	map->entries[map->size - 1].key = ft_strdup(key);
	if (map->entries[map->size - 1].key == NULL)
		return (false);
	map->entries[map->size - 1].value = ft_strdup(value);
	if (map->entries[map->size - 1].value == NULL)
		return (false);
	return (true);
}

/*
 * @return true if successful, false otherwise
 */
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
