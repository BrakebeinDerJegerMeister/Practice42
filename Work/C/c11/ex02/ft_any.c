/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:52:03 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/01 13:32:21 by profchaos        ###   ########.fr       */
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

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}

#include <stdio.h>

int	main(void)
{
	char	*strs1[] = {"hello", "world", "42", "a", "allo", NULL};
	char	*strs2[] = {"a", "b", "c", NULL};
	int		has_any;

	has_any = ft_any(strs1, &minlen_2);
	printf("%s\n", has_any ? "oui" : "non");
	has_any = ft_any(strs2, &minlen_2);
	printf("%s\n", has_any ? "oui" : "non");
}
