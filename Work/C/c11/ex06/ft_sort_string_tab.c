/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:04:21 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/02 16:25:57 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*comp;

	i = 1;
	while (tab[i - 1] && tab[i])
	{
		comp = tab[i];
		j = i - 1;
		while (j >= 0 && ft_strcmp(comp, tab[j]) < 0)
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
	ft_sort_string_tab(tab);
	print_tab(tab);
}
