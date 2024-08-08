/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:14:04 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/25 13:21:02 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_abs.h"
#include <stdio.h>

void	test(int x)
{
	printf("Nombre : {%d}\n", x);
	printf("Valeur absolue : {%d}\n\n", ABS(x));
}

int	main(void)
{
	test(50);
	test(-2500);
	test(-0);
	test(-1);
	return (0);
}
