/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:02:18 by kaos              #+#    #+#             */
/*   Updated: 2024/07/17 15:23:06 by kaos             ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

/*#include <stdio.h>

void	test(int nb)
{
	printf("\nnb : {%d}", nb);
	printf("\nnext nb : {%d}\n", ft_find_next_prime(nb));
}

int	main(void)
{
	test(50);
	test(0);
	test(110);
}*/
