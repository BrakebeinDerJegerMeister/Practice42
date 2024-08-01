/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:42:47 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/01 13:48:37 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	minlen_2(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
		if (i > 2)
			return (1);
	}
	return (0);
}

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i] != NULL)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}

#include <stdio.h>

int	main(void)
{
	char	*strs1[] = {"hello", "world", "42", "a", "allo", NULL};
	char	*strs2[] = {"a", "b", "c", NULL};
	int		count;

	count = ft_count_if(strs1, &minlen_2);
	printf("Count : %d\n", count);
	count = ft_count_if(strs2, &minlen_2);
	printf("Count : %d\n", count);
}
