/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:30:34 by kaos              #+#    #+#             */
/*   Updated: 2024/08/02 09:53:30 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	is_whitespace(char chr)
{
	if (chr == 32 || (chr > 8 && chr < 14))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		factor;
	int		nb;
	int		i;

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
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (int)str[i] - 48 + nb * 10;
		i++;
	}
	return (factor * nb);
}

/*#include <stdlib.h>
#include <stdio.h>

void	test(char *str)
{
	int	res;

	res = ft_atoi(str);
	printf("\nStr : {%s}\n", str);
	printf("ft_atoi : {%d}\n", res);
	printf("atoi : {%d}\n", atoi(str));
}

int	main(void)
{
	test("  ---+--+1234ab567");
	test("-1234ab567");
	test("-12-5");
	test("+45");
	test("-42");
	return (0);
}*/
