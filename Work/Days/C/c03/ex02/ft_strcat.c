/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:54:30 by kaos              #+#    #+#             */
/*   Updated: 2024/07/06 17:46:17 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*save;

	save = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (save);
}

/*#include <stdio.h>

void	test(char *dest, char *src)
{
	printf("dest : %s\nsrc : %s\n", dest, src);
	printf("%s\n", ft_strcat(dest, src));
}

int	main(void)
{
	char	s1[50] = "Ceci est un ";
	char	s2[50] = "Voici";
	char	s3[50] = "Encore un test";
	char	s4[50] = "";

	test(s1, "test");
	test(s2, " un autre test");
	test(s3, "");
	test(s4, "Test final");
	return (0);
}*/
