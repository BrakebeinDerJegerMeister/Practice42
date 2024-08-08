/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:03:16 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/02 11:28:29 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	init(int (**op_fcts)(int, int, int *), char *ops)
{
	op_fcts[0] = add;
	op_fcts[1] = sub;
	op_fcts[2] = mul;
	op_fcts[3] = div;
	op_fcts[4] = mod;
	ops[0] = '+';
	ops[1] = '-';
	ops[2] = '*';
	ops[3] = '/';
	ops[4] = '%';
}

void	do_op(int a, int b, char *op)
{
	int		(*op_fcts[5])(int, int, int *);
	int		i;
	int		result;
	int		error;
	char	ops[5];

	init(op_fcts, ops);
	i = 0;
	while (i < 5)
	{
		if (ops[i] == op[0])
		{
			error = -1;
			result = op_fcts[i](a, b, &error);
			if (! error)
			{
				ft_putnbr(result);
				ft_putstr("\n");
			}
			return ;
		}
		i++;
	}
	ft_putstr("0\n");
}
