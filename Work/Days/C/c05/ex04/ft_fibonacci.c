/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:07:27 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/15 16:01:58 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fibonacci(int index)
{
	if (index > 1)
		return (fibonacci(index - 1) + fibonacci(index - 2));
	else
		return (index);
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	return (fibonacci(index));
}

/*#include <stdio.h>

void	test(int index)
{
	printf("\nindex : {%d}", index);
	printf("\nres : {%d}\n", ft_fibonacci(index));
}

int	main(void)
{
	test(0);
	test(1);
	test(2);
	test(3);
	test(4);
	test(-5);
	test(25);
	test(35);
	test(45);
	return (0);
}*/
