/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:13:50 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/24 13:03:28 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	get_strpos(char *str, char *to_find)
{
	int	i;
	int	j;
	int	is_good;

	if (*to_find == '\0')
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] != '\0')
		{
			is_good = 1;
			if (str[i + j] == '\0' || str[i + j] != to_find[j])
			{
				is_good = 0;
				break ;
			}
			j++;
		}
		if (is_good)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	next(char *str, char *charset, int count, char ***array)
{
	int		charset_pos;
	int		charset_len;
	int		i;

	if (! *str)
	{
		*array = (char **)malloc(count + 1);
		(*array)[count] = NULL;
		return ;
	}
	charset_len = ft_strlen(charset);
	charset_pos = get_strpos(str, charset);
	printf("\n{%d}\n", charset_pos);
	if (charset_pos > 0)
	{
		next(str + charset_pos + charset_len, charset, count + 1, array);
		*(array)[count] = (char *)malloc(charset_pos + 1);
		*(array)[count][charset_pos] = '\0';
		i = 0;
		while (i < charset_pos)
		{
			*(array)[count][i] = str[i];
			i++;
		}
		printf("\n{%s}\n", *(array)[count]);
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**array;

	next(str, charset, 0, &array);
	return (array);
}

#include <stdio.h>

void	test(char *str, char *charset)
{
	char	**tab;

	tab = ft_split(str, charset);
	if (!tab)
		return ;
	while (*tab)
	{
		printf("%s\n", *tab);
		free(tab[0]);
		tab++;
	}
	free(tab);
}

int	main(void)
{
	test ("aaa--456f----hheh--tjjjjjj--uu", "--");
	return (0);
}
