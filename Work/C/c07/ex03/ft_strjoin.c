/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:36:15 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/22 16:48:56 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	get_full_size(int size, char **strs, char *sep)
{
	int	i;
	int	sz;

	sz = 0;
	i = 0;
	while (i < size)
	{
		sz += ft_strlen(strs[i]);
		if (i > 0)
			sz += ft_strlen(sep);
		i++;
	}
	return (sz);
}

void	fast_strcpy(char **dest, char *src)
{
	while (*src)
	{
		**dest = *src;
		(*dest)++;
		src++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	char	*tmp;
	int		sz;
	int		i;

	sz = 0;
	if (size > 0)
		sz = get_full_size(size, strs, sep);
	res = (char *)malloc(sz + 1);
	tmp = res;
	if (size > 0)
	{
		i = -1;
		while (++i < size)
		{
			fast_strcpy(&res, strs[i]);
			if (i < size - 1)
				fast_strcpy(&res, sep);
		}
	}
	*res = '\0';
	return (tmp);
}

/*#include <stdio.h>

void	test(int size, char **strs, char *sep)
{
	char	*res;

	res = ft_strjoin(size, strs, sep);
	printf("\nres : {%s}\n", res);
	free(res);
}

int	main(void)
{
	char *t1[] = {"aaa", "b", "cccc", "dd", "e"};
	char *t2[] = {"Miaou"};

	test(5, t1, "--");
	test(0, t1, "_");
	test(1, t2, " ");
	return (0);
}*/
