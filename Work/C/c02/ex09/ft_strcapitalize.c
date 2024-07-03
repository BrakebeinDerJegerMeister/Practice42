/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:35:29 by kaos              #+#    #+#             */
/*   Updated: 2024/07/03 16:54:01 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	c;
	char	b;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (i > 0)
			b = str[i - 1];
		else
			b = ' ';
		if (b == ' ' || b == '+' || b == '-')
			if (c >= 'a' && c <= 'z')
				str[i] = c - 32;
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
	ret = ft_strcapitalize(str);
	ft_putstr(ret);
	write(1, "\n", 1);
}

int	main(void)
{
	char	str1[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char	str2[] = "ceci est un autre essai";

	test(str1);
	test(str2);
	return (0);
}*/
