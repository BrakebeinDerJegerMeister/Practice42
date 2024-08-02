/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:04:21 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/02 12:56:14 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	sort_asc(char *s1, char *s2)
{
	char	c1;
	char	c2;

	while (*s1 != '\0' && *s2 != '\0')
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 != c2)
			return (c1 - c2);
	}
	return (c1 - c2);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		c;
	char	*comp;

	i = 1;
	while (tab[i - 1] && tab[i])
	{
		comp = tab[i];
		j = i;
		while (j > 0)
		{
			j--;
			c = sort_asc(comp, tab[j - 1]);
			if (c > 0)
			{
				tab[j + 1] = tab[j];
				break ;
			}
		}
		tab[j] = comp;
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
