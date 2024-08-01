/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:26:18 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/01 12:24:27 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	square(int nb)
{
	return (nb * nb);
}

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*ret;

	ret = malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		ret[i] = f(tab[i]);
		i++;
	}
	return (ret);
}

#include <stdio.h>

void	disp(int *t, int l)
{
	int	i;

	i = 0;
	printf("{");
	while (i < l)
	{
		printf("%d", t[i]);
		i++;
		if (i < l)
			printf(", ");
	}
	printf("}\n");
}

int	main(void)
{
	int	t[5] = {10, -5, 3, 9, 100};
	int	*r;

	r = malloc(5);
	disp(t, 5);
	r = ft_map(t, 5, &square);
	disp(r, 5);
	free(r);
	return (0);
}
