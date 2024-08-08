/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 23:42:48 by kaos              #+#    #+#             */
/*   Updated: 2024/07/21 00:25:22 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	sort_me_asc(int nb, char **strings)
{
	int		i;
	int		j;
	char	*str;

	i = 2;
	while (i < nb)
	{
		str = strings[i];
		j = i - 1;
		while (j >= 1 && (ft_strcmp(strings[j], str) > 0))
		{
			strings[j + 1] = strings[j];
			j--;
		}
		strings[j + 1] = str;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	sort_me_asc(argc, argv);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
