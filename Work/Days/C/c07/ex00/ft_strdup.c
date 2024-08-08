/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:43:54 by kaos              #+#    #+#             */
/*   Updated: 2024/07/21 13:13:06 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	new = (char *)malloc(i + 1);
	i = 0;
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*#include <stdio.h>

void	test(char *str)
{
	char	*res;

	printf("\nsrc : {%s}", str);
	res = ft_strdup(str);
	printf("\nres : {%s}\n", res);
}

int	main(void)
{
	test("Coucou");
	test("C'est le masupilami : Houba houba");
	return (0);
}*/
