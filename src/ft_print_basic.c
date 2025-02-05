/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:32:23 by llage             #+#    #+#             */
/*   Updated: 2024/12/18 22:24:52 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_char(const char c)
{
	return (write(1, &c, 1));
}

ssize_t	print_str(const char *str)
{
	size_t	n;

	if (str == NULL)
		return (write(1, "(null)", 6));
	n = 0;
	while (str[n])
		n++;
	return (write(1, str, n));
}

ssize_t	print_nbr(long n)
{
	ssize_t	char_count;

	char_count = 0;
	if (n < 0)
	{
		char_count += print_char('-');
		n = -n;
	}
	if (n > 9)
		char_count += print_nbr(n / 10);
	char_count += print_char('0' + (n % 10));
	return (char_count);
}

ssize_t	print_unbr(unsigned int n)
{
	ssize_t	char_count;

	char_count = 0;
	if (n > 9)
		char_count += print_nbr(n / 10);
	char_count += print_char('0' + (n % 10));
	return (char_count);
}
