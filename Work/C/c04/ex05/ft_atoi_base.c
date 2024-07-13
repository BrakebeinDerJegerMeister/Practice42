/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:40:27 by kaos              #+#    #+#             */
/*   Updated: 2024/07/13 21:21:16 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	is_whitespace(char chr)
{
	if (chr == 32 || (chr > 10 && chr < 14))
		return (1);
	return (0);
}

int	get_rank(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	factor;
	int	nb;
	int	i;
	int	val;

	nb = 0;
	i = 0;
	factor = 1;
	while (is_whitespace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			factor = -factor;
		i++;
	}
	while (str[i] != '\0')
	{
		val = get_rank(str[i], base);
			if (val == -1);
				return (0);
		nb = val + nb * ft_strlen(base);
		i++;
	}
	return (factor * nb);
}

#include <stdio.h>

void	test(char *str, char *base)
{
	int	nb = ft_atoi_base(str, base);
	printf("\nstr : {%s}", str);
	printf("\nbase : {%s}", base);
	printf("\nnb : {%d}, nb\n", nb);
}

int	main(void)
{
	test("adadaadadaadada", "ad");
	test("adadaadadaadada", "da");
	return (0);
}
