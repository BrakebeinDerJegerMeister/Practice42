/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:33:43 by kaos              #+#    #+#             */
/*   Updated: 2024/07/06 11:58:43 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	char			c1;
	char			c2;

	i = 0;
	while (i < n)
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 < c2)
			return (-1);
		if (c1 > c2)
			return (1);
		if (c1 == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

void	test(char *s1, char *s2, unsigned int n)
{
	int	res;

	res = ft_strcmp(s1, s2, n);
	printf("%s\n%s\n", s1, s2);
	if (res == 0)
	{
		printf("Chaîne 1 = Chaîne 2");
	}
	else if (res > 0)
	{
		printf("Chaîne 1 > Chaîne 2");
	}
	else
	{
		printf("Chaîne 1 < Chaîne 2");
	}
	printf("\n");
}

int	main(void)
{
	test("Super test 1", "Super test 2", 10);
	test("Super test 3", "Super test", 11);
	test("Super test", "Super test", 30);
	return (0);
}*/
