/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:34:11 by kaos              #+#    #+#             */
/*   Updated: 2024/07/21 17:32:26 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	if (max - min <= 0)
		return (NULL);
	res = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (i < max - min)
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}

/*#include <stdio.h>

void	test(int min, int max)
{
	int	*res;
	int	i;

	printf("\nmin : {%d}", min);
	printf("\nmax : {%d}", max);
	res = ft_range(min, max);
	printf("\nres : {");
	if (!res)
		printf("NULL");
	else
	{
		i = 0;
		printf("(size : %d) ", i);
		while (i < max - min)
		{
			printf("%d", res[i]);
			if (i < max - min - 1)
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
