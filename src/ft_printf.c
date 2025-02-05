/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:12:49 by llage             #+#    #+#             */
/*   Updated: 2024/12/19 01:23:46 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_arg(va_list args, char type)
{
	ssize_t	char_count;

	char_count = 0;
	if (type == 'c')
		char_count += print_char(va_arg(args, int));
	else if (type == 's')
		char_count += print_str(va_arg(args, char *));
	else if (type == 'p')
		char_count += print_ptr(va_arg(args, void *));
	else if (type == 'd' | type == 'i')
		char_count += print_nbr(va_arg(args, int));
	else if (type == 'u')
		char_count += print_unbr(va_arg(args, unsigned int));
	else if (type == 'x')
		char_count += print_nbr_hex(va_arg(args, unsigned int), true);
	else if (type == 'X')
		char_count += print_nbr_hex(va_arg(args, unsigned int), false);
	else if (type == '%')
		char_count += print_char('%');
	return (char_count);
}

bool	is_valid_specifier(const char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

int	ft_printf(const char *str, ...)
{
	ssize_t	char_count;
	va_list	args;
	int		i;

	va_start(args, str);
	char_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_valid_specifier(str[i + 1]))
		{
			i++;
			char_count += print_arg(args, str[i++]);
		}
		else
			char_count += print_char(str[i++]);
	}
	va_end(args);
	return (char_count);
}
