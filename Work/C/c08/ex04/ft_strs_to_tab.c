/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:06:45 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/26 12:58:15 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*save;

	save = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (save);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	char		*cpy;
	t_stock_str	*stk;

	cpy = NULL;
	stk = (t_stock_str *)malloc(sizeof(t_stock_str) * (1 + ac));
	if (!stk)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stk[i].size = ft_strlen(av[i]);
		stk[i].str = av[i];
		free(cpy);
		stk[i].copy = malloc((stk[i].size + 1) * sizeof(char));
		if (!stk[i].copy)
			return (NULL);
		ft_strcpy(stk[i].copy, av[i]);
		i++;
	}
	stk[ac].str = 0;
	free(cpy);
	return (stk);
}

#include <stdio.h>

void	print_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		printf("\n------ Entrée %d ------\n", i);
		printf("size : {%d}\n", par[i].size);
		printf("str : {%s}\n", par[i].str);
		par[i].copy[0] = 'Z';
		printf("copy : {%s}\n", par[i].copy);
		i++;
	}
}

int	main(void)
{
	char		*av[] = {"Hello", "World", "Test", "Example"};
	t_stock_str	*stk;

	stk = ft_strs_to_tab(4, av);
	if (stk != NULL)
	{
		print_tab(stk);
	}
	return (0);
}
