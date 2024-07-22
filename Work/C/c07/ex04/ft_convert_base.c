/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:51:46 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/22 15:37:06 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 1)
		return (0);
	return (i);
}

int	int	ft_atoi_base(char *str, char *base)
{
	int	factor;
	int	ibase;
	int	nb;
	int	val;

	factor = 1;
	nb = 0;
	ibase = check_base(base);
	if (ibase == 0)
		return (0);
	while (str[0] == 32 || (str[0] > 8 && str[0] < 14))
		str++;
	while (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			factor = -factor;
		str++;
	}
	while(str[0] != '\0')
	{
		val = get_rank(str[0], base);
		nb = val + nb * ibase;
		str++;
	}
	return (nb * factor);
}

int	ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	factor;
	int	nb;
	int	i;
	int	ibase_from;
	int	ibase_to;

	nb = 0;
	i = 0;
	factor = 1;
	ibase_from = check_base(base_from);
	ibase_to = check_base(base_to);
	if (! (ibase_from && ibase_to))
		return (0);
	while (nbr == 32 || (nbr > 8 && nbr < 14))
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (str[i] == '-')
			factor = -factor;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (int)str[i] - 48 + nb * 10;
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
	printf("\nnb : {%d}\n", nb);
}

int	main(void)
{
	test("adadaadadaadada", "ad", "ok");
	test("adadaadadaadada", "da", "ok");
	test("adadaadadaadada", "mn", "prout");
	test("aaaaaa", "a", "bk");
	test("    +---+215", "0123456789", "0123456789ABCDEF");
	test("-eyfpnvofoy", "poneyvif", "foin");
	return (0);
}
