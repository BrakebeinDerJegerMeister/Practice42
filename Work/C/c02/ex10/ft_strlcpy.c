/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:44:51 by kaos              #+#    #+#             */
/*   Updated: 2024/07/03 20:10:32 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		if (i < (size - 1))
			dest[i] = src[i];
		i++;
	}
	dest[size - 1] = '\0';
	return (i);
}

/*#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	nextnumber(int nb)
{
	char	disp;
	int		next;

	next = nb % 10;
	disp = next + '0';
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		nextnumber(nb);
	}
	write(1, &disp, 1);
}

int	main(void)
{
	char	str1[] = "Exemple vraiment parfait";
	char	dst1[30];
	int		res1;
	char	str2[] = "Autre";
	char	dst2[30];
	int		res2;

	ft_putstr(str1);
	write(1, "\n", 1);
	res1 = ft_strlcpy(dst1, str1, 10);
	ft_putstr(dst1);
	write(1, "\n", 1);
	nextnumber(res1);
	write(1, "\n", 1);

	ft_putstr(str2);
	write(1, "\n", 1);
	res2 = ft_strlcpy(dst2, str2, 10);
	ft_putstr(dst2);
	write(1, "\n", 1);
	nextnumber(res2);
	write(1, "\n", 1);
	return (0);
}*/
