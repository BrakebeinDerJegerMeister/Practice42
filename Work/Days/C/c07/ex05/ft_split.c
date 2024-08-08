/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:13:50 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/25 10:51:48 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
}

void	next(char *str, char *charset, int count, char ***array)
{
	int	cpos;
	int	clen;
	int	slen;

	cpos = get_strpos(str, charset);
	clen = ft_strlen(charset);
	if (cpos == 0)
		next(str + clen, charset, count, array);
	else if (cpos > 0)
	{
		next(str + cpos + clen, charset, count + 1, array);
		mystrcpy(&(*array)[count], str, cpos);
	}
	else if (*str && cpos == -1)
	{
		slen = ft_strlen(str);
		next(str + slen, charset, count + 1, array);
		mystrcpy(&(*array)[count], str, slen);
	}
	if (*str == '\0' && cpos == -1)
	{
		*array = (char **)malloc((count + 1) * 8);
		(*array)[count] = NULL;
	}
	return ;
}

char	**ft_split(char *str, char *charset)
{
	char	**array;

	next(str, charset, 0, &array);
	return (array);
}

/*#include <stdio.h>

void	test(char *str, char *charset)
{
	char	**tab;
	int		i;

	tab = ft_split(str, charset);
	if (!tab)
		return ;
	i = 0;
	printf("====================\n");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	printf("====================\n\n");
}

int	main(void)
{
	test("aaa--456f----hheh--tjjjjjm--oyyyyo", "--");
	test("012301456045600789f0ffzt0hrtjj00jrj000", "0");
	return (0);
}*/
