/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:38:32 by kaos              #+#    #+#             */
/*   Updated: 2024/07/07 11:07:25 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*save;

	save = dest;
	while (*dest)
		dest++;
	while (*src && nb)
	{
		*dest++ = *src++;
		nb--;
	}
	*dest = '\0';
	return (save);
}

/*#include <stdio.h>

void	test(char *dest, char *src, unsigned int nb)
{
	printf("dest : %s\nsrc : %s\n", dest, src);
	printf("res : {%s}\n", ft_strncat(dest, src, nb));
}

int	main(void)
{
	char	s1[50] = "Ceci est un ";
	char	s2[50] = "Voici";
	char	s3[50] = "Encore un test";
	char	s4[50] = "";

	test(s1, "test", 8);
	test(s2, " un autre test", 9);
	test(s3, "",6);
	test(s4, "Test final",0);
	return (0);
}*/
