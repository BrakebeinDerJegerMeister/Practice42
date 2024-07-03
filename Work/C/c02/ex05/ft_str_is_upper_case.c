/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_upper_case.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:19:03 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/03 12:25:48 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (!(c >= 'A' && c <= 'Z'))
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

	ret = ft_str_is_uppercase(str);
	ft_putstr(str);
	if (ret)
		write(1, "\nOui\n", 5);
	else
		write(1, "\nNon\n", 5);
}

int	main(void)
{
	test("aiZERTbrh");
	test("ABCEZ");
	test("EFGH_");
	return (0);
}*/
