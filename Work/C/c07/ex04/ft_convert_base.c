/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:51:46 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/24 10:34:02 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

long	atoi_positive_base(char *str, char *base, int ibase)
{
	int		i;
	long	nb;
	int		val;
	int		j;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		val = -1;
		j = -1;
		while (++j < ibase)
		{
			if (base[j] == str[i])
			{
				val = j;
				break ;
			}
		}
		if (val == -1)
			return (0);
		nb = val + nb * ibase;
		i++;
	}
	return (nb);
}

char	*my_strcat(char *str1, char *str2)
{
	char	*new;
	char	*save;
	int		i;

	i = 0;
	while (str1[i] != '\0')
		i++;
	while (str2[i] != '\0')
		i++;
	new = (char *)malloc(i + 1);
	save = new;
	while (*str1)
		*new++ = *str1++;
	while (*str2)
		*new++ = *str2++;
	*new = '\0';
	return (save);
}

char	*get_positive_nbrbase(long nb, char *base, int ibase)
{
	long	current;
	char	*str1;
	char	*str2;

	current = nb % ibase;
	nb = (nb - current) / ibase;
	if (nb != 0)
		str1 = get_positive_nbrbase(nb, base, ibase);
	else
		str1 = "";
	str2 = my_strcat(str1, (char []){base[current], '\0'});
	return (str2);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		factor;
	int		ibase_from;
	int		ibase_to;
	long	nb1;
	char	*nb2;

	factor = 1;
	ibase_from = check_base(base_from);
	ibase_to = check_base(base_to);
	if (ibase_from == 0 || ibase_to == 0)
		return (NULL);
	while (nbr[0] == 32 || (nbr[0] > 8 && nbr[0] < 14))
		nbr++;
	while (nbr[0] == '-' || nbr[0] == '+')
	{
		if (nbr[0] == '-')
			factor = -factor;
		nbr++;
	}
	nb1 = atoi_positive_base(nbr, base_from, ibase_from);
	nb2 = get_positive_nbrbase(nb1, base_to, ibase_to);
	if (factor == -1)
		nb2 = my_strcat("-", nb2);
	return (nb2);
}

/*#include <stdio.h>

void	test(char *str, char *base_from, char *base_to)
{
	char	*nb = ft_convert_base(str, base_from, base_to);
	printf("\nstr : {%s}", str);
	printf("\nbase from : {%s}", base_from);
	printf("\nbase to : {%s}", base_to);
	printf("\nnb : {%s}\n", nb);
	free(nb);
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
}*/
