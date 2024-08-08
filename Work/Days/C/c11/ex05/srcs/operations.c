/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:34:19 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/02 10:24:04 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	add(int a, int b, int *err)
{
	*err = 0;
	return (a + b);
}

int	sub(int a, int b, int *err)
{
	*err = 0;
	return (a - b);
}

int	mul(int a, int b, int *err)
{
	*err = 0;
	return (a * b);
}

int	div(int a, int b, int *err)
{
	if (b == 0)
	{
		*err = 1;
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
	return (a / b);
}

int	mod(int a, int b, int *err)
{
	if (b == 0)
	{
		*err = 1;
		ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
	return (a % b);
}
