/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:34:19 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/01 15:49:47 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	add(int a, int b, char *msg)
{
	(void)*msg;
	return (a + b);
}

int	sub(int a, int b, char *msg)
{
	(void)*msg;
	return (a - b);
}

int	mul(int a, int b, char *msg)
{
	(void)*msg;
	return (a * b);
}

int	div(int a, int b, char *msg)
{
	if (b == 0)
	{
		*msg = "Stop : division by zero\n";
		return (0);
	}
	return (a / b);
}

int	mod(int a, int b, char *msg)
{
	if (b == 0)
	{
		*msg = "Stop : modulo by zero\n";
		return (0);
	}
	return (a % b);
}
