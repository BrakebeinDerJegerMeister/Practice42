/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:40:38 by kaos              #+#    #+#             */
/*   Updated: 2024/08/02 09:55:58 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

/*int	main(void)
{
	ft_putstr("42");
	ft_putstr("\n");
	ft_putstr("Bla bla bla");
	ft_putstr("\n");
	return (0);
}*/
