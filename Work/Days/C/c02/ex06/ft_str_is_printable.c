/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:43:33 by kaos              #+#    #+#             */
/*   Updated: 2024/07/03 14:56:15 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (!(c > 31 && c < 127))
		{
			return (0);
		}
		i++;
	}
	return (1);
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
	int	ret;

	ret = ft_str_is_printable(str);
	ft_putstr(str);
	if (ret)
		write(1, "\nOui\n", 5);
	else
		write(1, "\nNon\n", 5);
}

int	main(void)
{
	test("~~~ Bienvenue @ chez 42 ~~~");
	test("\x07Alerte système! \x02Gestion\x03.");
	test("Mise à jour \x1Brequise\x1C immédiatement!");
	return (0);
}*/
