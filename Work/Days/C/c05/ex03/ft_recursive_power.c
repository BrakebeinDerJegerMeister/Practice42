/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:21:49 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/15 15:01:24 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fast_recursive_power(int nb, int power)
{
	if (power > 0)
		return (nb * fast_recursive_power(nb, power - 1));
	return (1);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	return (fast_recursive_power(nb, power));
}

/*#include <stdio.h>

void	test(int nb, int power)
{
	printf("\nnb : {%d}, power : {%d}", nb, power);
	printf("\nres : {%d}\n", ft_recursive_power(nb, power));
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
