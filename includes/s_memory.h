/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_memory.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:53:52 by llage             #+#    #+#             */
/*   Updated: 2025/08/23 02:36:40 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MEMORY_H

# define S_MEMORY_H

# include <libft.h>

void	*s_alloc(size_t size, size_t num);
void	s_free(void **ptr);

#endif
