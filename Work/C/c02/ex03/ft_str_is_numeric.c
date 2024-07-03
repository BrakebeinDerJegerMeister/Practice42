/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:50:18 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/03 11:55:05 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (!(c >= '0' && c <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*#include <unistd.h>

int	main(void)
{
	int	is1;
	int	is2;

	is1 = ft_str_is_numeric("9011110");
	is2 = ft_str_is_numeric("12309a");
	if (is1)
		write(1, "Oui\n", 4);
	else
		write(1, "Non\n", 4);
	if (is2)
		write(1, "Oui\n", 4);
	else
		write(1, "Non\n", 4);
}*/
