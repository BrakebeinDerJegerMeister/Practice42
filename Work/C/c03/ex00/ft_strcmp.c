/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:57:08 by kaos              #+#    #+#             */
/*   Updated: 2024/07/06 11:11:16 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	char	c1;
	char	c2;

	i = 0;
	while (1)
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
}

/*#include <stdio.h>

void	test(char *s1, char *s2)
{
	int	res;

	res = ft_strcmp(s1, s2);
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
	test("Super test 1", "Super test 2");
	test("Super test 3", "Super test");
	test("Super test", "Super test");
	return (0);
}*/
