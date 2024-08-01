/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:22:15 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/01 14:48:45 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	desc(int a, int b)
{
	return (b - a);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>

int	main(void)
{
	int	t1[5] = {10, -5, 3, 9, 100};
	int	t2[5] = {0, 1, 2, 3, 4};
	int	r;

	r = ft_is_sort(t1, 5, desc);
	printf("%s\n", r ? "oui" : "non");
	r = ft_is_sort(t2, 5, desc);
	printf("%s\n", r ? "oui" : "non");
	return (0);
}
