/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:04:01 by profchaos         #+#    #+#             */
/*   Updated: 2024/06/27 16:38:13 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_me(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	char	c;

	if (n < 0)
	{
		c = 'N';
	}
	else
	{
		c = 'P';
	}
	print_me(c);
}

/*int	main(void)
{
	ft_is_negative(3);
	ft_is_negative(-3);
	ft_is_negative(0);
	ft_is_negative(100);
	ft_is_negative(90);
	ft_is_negative(-50);
	return (0);
}*/
