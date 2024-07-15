/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:53:02 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/15 14:13:09 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb > 0)
		return (nb * ft_recursive_factorial(nb -1));
	if (nb < 0)
		return (0);
	else
		return (1);
}

/*#include <stdio.h>

void	test(int nb)
{
	printf("\nnb : {%d}", nb);
	printf("\nres : {%d}\n", ft_recursive_factorial(nb));
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
