/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:59:42 by kaos              #+#    #+#             */
/*   Updated: 2024/07/02 13:04:45 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	char	*save;

	save = dest;
	while (n-- && *src)
	{
		*dest++ = *src++;
		//write(1, "~", 1);
	}
	n++;
	while (n--)
	{
		*dest++ = '\0';
		//write(1, ".", 1);
	}
	//write(1, "\n", 1);
	return (save);
}

/*void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(void)
{
	char	src1[] = "Hello 42";
	char	dest1[15];
	char	*res1;
	char	src2[] = "Hello 42";
	char	dest2[15];
	char	*res2;

	ft_putstr(src1);
	write(1, "\n", 1);
	res1 = ft_strncpy(dest1, src1, 12);
	ft_putstr(dest1);
	write(1, "\n", 1);
	ft_putstr(res1);
	write(1, "\n", 1);

	ft_putstr(src2);
	write(1, "\n", 1);
	res2 = ft_strncpy(dest2, src2, 5);
	dest2[5] = '\0';
	ft_putstr(dest2);
	write(1, "\n", 1);
	ft_putstr(res2);
	write(1, "\n", 1);
}*/
