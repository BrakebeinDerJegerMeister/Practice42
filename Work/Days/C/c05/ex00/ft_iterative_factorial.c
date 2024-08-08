/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:04:51 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/15 13:46:51 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	factorial;

	factorial = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		factorial = factorial * nb;
		nb--;
	}
	return (factorial);
}

/*#include <stdio.h>

void	test(int nb)
{
	printf("\nnb : {%d}", nb);
	printf("\nres : {%d}\n", ft_iterative_factorial(nb));
}

int	main(void)
{
	test(3);
	test(-2);
	test(25);
	test(8);
	test(0);
	return (0);
}*/
