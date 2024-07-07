/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:05:11 by kaos              #+#    #+#             */
/*   Updated: 2024/07/07 17:12:45 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	is_good;

	if (*to_find == '\0')
		return (str);
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
			return (str + i);
		i++;
	}
	return ((void *)0);
}

/*#include <stdio.h>

void	test(char *dest, char *to_find)
{
	printf("\ndest : %s\nto find : %s\n", dest, to_find);
	printf("ret : {%s}\n\n", ft_strstr(dest, to_find));
}

int	main(void)
{
	test("Ma phrase de test", "Ma super recherche trop grande");
	test("Ma phrase de test", "phrase");
	test("Ma phrase de test", "");
	test("Ma phrase de test", "recherche");
	return (0);
}*/
