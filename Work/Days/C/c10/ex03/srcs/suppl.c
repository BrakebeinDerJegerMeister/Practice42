/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suppl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:03:15 by kaos              #+#    #+#             */
/*   Updated: 2024/07/31 23:04:24 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	print_addr(int addr, char *next)
{
	int		i;
	char	hex;

	i = 8;
	while (i-- > 0)
	{
		hex = hex_digit((addr >> (4 * i)) & 0xF);
		write(1, &hex, 1);
	}
	while (*next)
	{
		write(1, next++, 1);
	}
}

char	hex_digit(char c)
{
	return (c + '0' + (c > 9) * 39);
}

void	putstr_err(char *str)
{
	while (*str)
	{
		write(2, str++, 1);
	}
}

void	copy_16(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		s1[i] = s2[i];
		i++;
	}
}

int	is_equal_16(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
