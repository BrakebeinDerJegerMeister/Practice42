/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:33:42 by kaos              #+#    #+#             */
/*   Updated: 2024/08/02 16:39:21 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*comp;

	i = 1;
	while (tab[i - 1] && tab[i])
	{
		comp = tab[i];
		j = i - 1;
		while (j >= 0 && cmp(comp, tab[j]) < 0)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		if (j < i - 1)
			tab[j + 1] = comp;
		i++;
	}
}

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	print_tab(char **tab)
{
	printf("Tab :\n");
	while (*tab)
	{
		printf("- %s\n", *tab++);
	}
	printf("\n");
}

int	main(void)
{
	char	*tab[5] = {"Lion", "Chaton", "Chat", "Kangourou", NULL};

	print_tab(tab);
	ft_sort_string_tab(tab, ft_strcmp);
	print_tab(tab);
}
