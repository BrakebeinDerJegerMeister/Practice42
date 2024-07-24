/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:13:50 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/24 22:36:25 by kaos             ###   ########.fr       */
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

void	mystrcpy(char **str, char *from, int len)
{
	int	i;

	*str = (char *)malloc(len + 1);
	(*str)[len] = '\0';
	i = 0;
	while (i < len)
	{
		(*str)[i] = from[i];
		i++;
	}
	printf("\ncharset_pos : {%d}, string : {%s}\n", len, *str);
}

void	next(char *str, char *charset, int counts[], char ***array)
{
	int		charset_pos;
	int		charset_len;

	printf("\n----------------------------");
	printf("\ncount[0] : {%d}\n", counts[0]);
	printf("count[1] : {%d}", counts[1]);
	charset_len = ft_strlen(charset);
	charset_pos = get_strpos(str, charset);
	printf("\ncharset_pos : {%d}", charset_pos);
	printf("\n str : {%s}", str);
	if (charset_pos == 0)
	{
		next(str + charset_len, charset, counts, array);
	}
	else if (charset_pos > 0)
	{
	next(str + charset_pos + charset_len, charset, (int[2]){counts[0] + 1, counts[1] + charset_pos + 1}, array);
	mystrcpy(&(*array)[counts[0]], str, charset_pos);
	}
	else if (*str && charset_pos == -1)
	{
		next(str + ft_strlen(str), charset, (int[2]){counts[0] + 1, counts[1] + ft_strlen(str) + 1}, array);
		mystrcpy(&(*array)[counts[0]], str, ft_strlen(str));
	}
	if (*str == '\0' && charset_pos == -1)
	{
		printf("\n@@@ FIN @@@\n");
		*array = (char **)malloc(counts[1] + 1);
		(*array)[counts[1]] = NULL;
	}
	return ;
}

char	**ft_split(char *str, char *charset)
{
	char	**array;

	next(str, charset, (int[2]){0, 0}, &array);
	return (array);
}

#include <stdio.h>

void	test(char *str, char *charset)
{
	char	**tab;
	int		i;

	tab = ft_split(str, charset);
	if (!tab)
		return ;
	i = 0;
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(void)
{
	test ("aaa--456f----hheh--tjjjjjj--yyyyyy", "--");
	return (0);
}
