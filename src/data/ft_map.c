/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 23:31:51 by llage             #+#    #+#             */
/*   Updated: 2025/08/14 23:31:51 by llage            ###   ########.fr       */
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

/*
 * @return true if sucessful, false otherwise
 */
bool	map_set(t_map *map, char *key, char *value)
{
	t_map_entry	*temp;
	size_t		i;

	temp = ft_calloc(map->size + 1, sizeof(t_map_entry));
	if (temp == NULL)
		return (false);
	i = 0;
	while (i < map->size)
	{
		temp[i].key = map->entries[i].key;
		temp[i].value = map->entries[i].value;
	}
	free(map->entries);
	map->entries = temp;
	map->size++;
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

char	*map_get(t_map *map, char *key)
{
	const size_t	key_len = ft_strlen(key);
	char			*cur_key;
	size_t			i;

	i = 0;
	while (i < map->size)
	{
		cur_key = map->entries[i].key;
		if (cur_key != NULL && ft_strlen(cur_key) == key_len
			&& !ft_strncmp(key, cur_key, key_len + 1))
			return (map->entries[i].value);
		i++;
	}
	return (NULL);
}

void	map_unset(t_map *map, char *key)
{
	const size_t	key_len = ft_strlen(key);
	char			*cur_key;
	size_t			i;

	i = 0;
	while (i < map->size)
	{
		cur_key = map->entries[i].key;
		if (cur_key != NULL && ft_strlen(cur_key) == key_len
			&& !ft_strncmp(key, cur_key, key_len + 1))
		{
			free(map->entries[i].key);
			map->entries[i].key = NULL;
			return ;
		}
		i++;
	}
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
