/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:02:12 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/02 11:19:35 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc != 4)
		return (1);
	if (ft_strlen(argv[2]) != 1)
	{
		ft_putstr("0\n");
		return (1);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	do_op(a, b, argv[2]);
	return (0);
}
