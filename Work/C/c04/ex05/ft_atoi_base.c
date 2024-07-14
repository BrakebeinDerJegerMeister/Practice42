/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:40:27 by kaos              #+#    #+#             */
/*   Updated: 2024/07/14 13:37:59 by kaos             ###   ########.fr       */
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

int	check_base_error(char *base, int ibase)
{
	int	i;
	int	j;

	if (ibase == 0 || ibase == 1)
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_val(char *str, char *base, int ibase)
{
	int	i;
	int	val;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		val = get_rank(str[i], base);
		if (val == -1)
			return (0);
		nb = val + nb * ibase;
		i++;
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int	factor;
	int	ibase;

	factor = 1;
	ibase = 0;
	while (base[ibase] != '\0')
		ibase++;
	if (check_base_error(base, ibase))
		return (0);
	while (str[0] == 32 || (str[0] > 8 && str[0] < 14))
		str++;
	while (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			factor = -factor;
		str++;
	}
	return (get_val(str, base, ibase) * factor);
}

/*#include <stdio.h>

void	test(char *str, char *base)
{
	int	nb = ft_atoi_base(str, base);
	printf("\nstr : {%s}", str);
	printf("\nbase : {%s}", base);
	printf("\nnb : {%d}\n", nb);
}

int	main(void)
{
	test("adadaadadaadada", "ad");
	test("adadaadadaadada", "da");
	test("adadaadadaadada", "mn");
	test("aaaaaa", "a");
	test("    +---+215", "0123456789");
	test("-eyfpnvofoy", "poneyvif");
	return (0);
}*/
