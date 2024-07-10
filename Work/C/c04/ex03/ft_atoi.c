/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:30:34 by kaos              #+#    #+#             */
/*   Updated: 2024/07/10 21:54:35 by kaos             ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int		len;
	int		rank;
	int		nb;
	char	chr;

	rank = 0;
	len = ft_strlen(str);
	nb = 0;
	while(len>0) {
		chr = str[len - 1];
		if (chr >= '0' && chr <= '0')
			rank++;
		else
			rank = 0;
		if (chr == '-')
			nb = -nb;
		
		len--;
	}
	return (nb);

}

#include <stdlib.h>
#include <stdio.h>

void	test(char *str)
{
	int	res;

	res = ft_atoi(str);
	printf("\nStr : {%s}\n", str);
	printf("ft_atoi : {%d}\n", res);
	printf("atoi : {%d}\n", atoi(str));
}

int	main(void)
{
	test("  ---+--+1234ab567");
	test("-1234ab567");
	test("-12-5");
	test("+45");
	test("-42");
	return (0);
}
