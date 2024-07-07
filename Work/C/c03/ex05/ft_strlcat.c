/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:19:07 by kaos              #+#    #+#             */
/*   Updated: 2024/07/07 20:36:47 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && dest_len + i < size -1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (dest_len + src_len);
}

/*#include <stdio.h>
#include <string.h>

void	test(char *dest, char *src, unsigned int size)
{
	printf("\nTaille du tampon : {%u}\n", size);
	printf("dest : {%s} - %lu\n", dest, strlen(dest));
	printf("src : {%s} - %lu\n", src, strlen(src));
	printf("Résultat : {%u}\n", ft_strlcat(dest, src, size));
	printf("dest : {%s} - %lu\n", dest, strlen(dest));
}

int	main(void)
{
	char	s1[50] = "Ceci est un ";
	char	s2[13] = "Voici";
	char	s3[50] = "Encore un test";
	char	s4[50] = "";

	test(s1, "test", 16);
	test(s2, " un autre test", 9);
	test(s3, "", 6);
	test(s4, "Test final", 0);
	return (0);
}*/
