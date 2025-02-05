/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:55:03 by llage             #+#    #+#             */
/*   Updated: 2024/12/18 20:52:41 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft.h"

int		ft_printf(const char *str, ...);

ssize_t	print_char(const char c);
ssize_t	print_str(const char *str);
ssize_t	print_ptr(const void *ptr);
ssize_t	print_nbr(long n);
ssize_t	print_unbr(unsigned int n);
ssize_t	print_nbr_hex(unsigned long n, bool lowercase);

#endif
