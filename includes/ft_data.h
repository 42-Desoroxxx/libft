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
#include <stddef.h>

typedef struct s_map_entry
{
	char	*key;
	char	*value;
}	t_map_entry;

typedef struct s_map
{
	t_map_entry	*entries;
	size_t		size;
};

#endif //FT_DATA_H
