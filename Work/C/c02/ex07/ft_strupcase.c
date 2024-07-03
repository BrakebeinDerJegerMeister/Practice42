/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:37:24 by kaos              #+#    #+#             */
/*   Updated: 2024/07/03 16:11:07 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c >= 'a' && c <= 'z')
		{
			str[i] = c - 32;
		}
		i++;
	}
	return (str);
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

void	test(char *str)
{
	char	*ret;

	ft_putstr(str);
	write(1, "\n", 1);
	ret = ft_strupcase(str);
	ft_putstr(ret);
	write(1, "\n", 1);
}

int	main(void)
{
	char	str1[] = "__ super Test __";
	char	str2[] = "Un autre test 0123";

	test(str1);
	test(str2);
	return (0);
}*/
