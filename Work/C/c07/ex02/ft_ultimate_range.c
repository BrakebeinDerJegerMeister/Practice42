/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:03:35 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/22 09:20:38 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*res;
	int	i;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	res = (int *)malloc(sizeof(int) * (max - min));
	if (res == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (i < max - min)
	{
		res[i] = min + i;
		i++;
	}
	*range = res;
	return (max - min);
}

/*#include <stdio.h>

void	test(int min, int max)
{
	int	*res;
	int	i;
	int	nb;

	printf("\nmin : {%d}", min);
	printf("\nmax : {%d}", max);
	nb = ft_ultimate_range(&res, min, max);
	printf("\nres : {");
	if (!res)
		printf("NULL");
	else
	{
		i = 0;
		printf("(size : %d) ", nb);
		while (i < nb)
		{
			printf("%d", res[i]);
			if (i < nb - 1)
				printf(", ");
			i++;
		}
	}
	printf("}\n");
}

int	main(void)
{
	test(50, 55);
	test(9, 4);
	test(-2, 8);
	return (0);
}*/
