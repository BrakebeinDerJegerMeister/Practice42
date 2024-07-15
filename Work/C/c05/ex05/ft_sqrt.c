/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:04:27 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/15 16:27:00 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	int_sqrt(int nb, int i)
{
	if ((i * i) == nb)
		return (i);
	else if ((i * i) > nb)
		return (0);
	else
		return (int_sqrt(nb, i + 1));
}

int	ft_sqrt(int nb)
{
	return (int_sqrt(nb, 0));
}

/*#include <stdio.h>

void	test(int nb)
{
	printf("\nnb : {%d}", nb);
	printf("\nsqrt : {%d}\n", ft_sqrt(nb));
}

int	main(void)
{
	test(25);
	test(0);
	test(-5);
	test(26);
	test(1);
	return (0);
}*/
