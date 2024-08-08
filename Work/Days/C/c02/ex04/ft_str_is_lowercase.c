/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:58:25 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/03 12:12:25 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (!(c >= 'a' && c <= 'z'))
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

	ret = ft_str_is_lowercase(str);
	ft_putstr(str);
	if (ret)
		write(1, "\nOui\n", 5);
	else
		write(1, "\nNon\n", 5);
}

int	main(void)
{
	test("aabghrh");
	test("eseggH");
	test("0qzqfq");
	return (0);
}*/
