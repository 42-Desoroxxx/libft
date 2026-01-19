/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:23:01 by llage             #+#    #+#             */
/*   Updated: 2025/08/30 18:05:25 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <libft.h>

// --- Management ---

void
*ft_calloc(size_t nmemb, size_t size);

void
ft_safe_free(void **ptr);

// --- Manipulation ---

void
*ft_memset(void *s, int c, size_t n) __attribute__((nonnull, returns_nonnull));

void
ft_bzero(void *s, size_t n) __attribute__((nonnull));

void
*ft_memcpy(void *dst, const void *src, size_t n);

void
*ft_memmove(void *dst, const void *src, size_t n);

// --- Misc ---

int
ft_memcmp(const void *s1, const void *s2, size_t n) __attribute__((nonnull));

void
*ft_memchr(const void *s, int c, size_t n) __attribute__((nonnull));

#endif
