/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:22:30 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/08 14:36:34 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

/*#include <stdio.h>

void	test(char *str)
{
	printf("\nStr : {%s}\nSize : {%d}\n", str, ft_strlen(str));
}

int	main(void)
{
	test("Coucou");
	test("");
	test("42");
	return (0);
}*/
