/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:58:41 by llage             #+#    #+#             */
/*   Updated: 2025/08/06 17:58:51 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_H

# define FT_DATA_H

# include <libft.h>
# include <stddef.h>

typedef struct s_map_entry
{
	char	*key;
	char	*value;
}	t_map_entry;

typedef struct s_map
{
	t_map_entry	*entries;
	size_t		size;
}	t_map;

t_map
map_bzero(void);

bool
map_set(t_map *map, char *key, char *value) __attribute__((nonnull (1, 2)));

char
*map_get(const t_map *map, char *key) __attribute__((nonnull));

void
map_print(const t_map *map) __attribute__((nonnull));

bool
map_unset(t_map *map, char *key) __attribute__((nonnull));

void
map_free(t_map *map) __attribute__((nonnull));

#endif // FT_DATA_H
