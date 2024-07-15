/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:21:49 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/15 14:38:11 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	res = 1;
	while (power > 0)
	{
		res = nb * res;
		power--;
	}
	return (res);
}

/*#include <stdio.h>

void	test(int nb, int power)
{
	printf("\nnb : {%d}, power : {%d}", nb, power);
	printf("\nres : {%d}\n", ft_iterative_power(nb, power));
}

int	main(void)
{
	test(3, 6);
	test(-2, 4);
	test(25, 2);
	test(8, 0);
	test(0, 5);
	test(0, 0);
	test(1, -3);
	return (0);
}*/
