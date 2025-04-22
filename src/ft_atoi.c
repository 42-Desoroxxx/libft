/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 05:33:55 by llage             #+#    #+#             */
/*   Updated: 2024/10/20 09:55:33 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static const char	*skip_whitespace(const char *nptr)
{
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	return (nptr);
}

int	ft_atoi(const char *nptr)
{
	long long	result;
	int			sign;

	nptr = skip_whitespace(nptr);
	sign = 1;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if ((sign == 1 && (result > (INT_MAX - (*nptr - '0')) / 10))
			|| (sign == -1
				&& (result > ((long)INT_MIN * -1 - (*nptr - '0')) / 10)))
		{
			if (sign == 1)
				return (INT_MAX);
			return (INT_MIN);
		}
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(result * sign));
}
