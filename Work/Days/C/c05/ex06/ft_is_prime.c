/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:21:02 by kaos              #+#    #+#             */
/*   Updated: 2024/07/17 14:52:12 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	if ((nb % 2) == 0 || (nb % 3) == 0)
		return (0);
	i = 5;
	while ((i * i) <= nb)
	{
		if ((nb % i) == 0 || (nb % (i + 2) == 0))
			return (0);
		i = i + 6;
	}
	return (1);
}

/*#include <stdio.h>

void	test(int nb)
{
	int	res;

	res = ft_is_prime(nb);
	printf("\nnb : {%d} ", nb);
	if (res == 1)
		printf("est premier.\n");
	else
		printf("n'est pas premier.\n");
}

int	main(void)
{
	test(-1);
	test(499);
	test(42);
	test(3);
	test(7777);
	test(111);
	test(112);
	test(113);
}*/
