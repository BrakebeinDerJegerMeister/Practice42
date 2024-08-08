/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:35:19 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/08 15:54:39 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_corner(int cx, int cy, int x, int y)
{
	if (cx == 1 && cy == 1)
		ft_putchar('/');
	else if (cx == 1 && cy == y)
		ft_putchar('\\');
	else if (cx == x && cy == y)
		ft_putchar('/');
	else if (cx == x && cy == 1)
		ft_putchar('\\');
}

void	print_other(int cx, int cy, int x, int y)
{
	if (((cx == 1 || cx == x) && (cy > 1 && cy < y))
		|| ((cx > 1 && cx < x) && (cy == 1 || cy == y)))
		ft_putchar('*');
	else if (cx > 1 && cx < x && cy > 1 && cy < y)
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	cx;
	int	cy;

	cx = 0;
	cy = 0;
	while (++cy <= y)
	{
		while (++cx <= x)
		{
			print_corner(cx, cy, x, y);
			print_other(cx, cy, x, y);
			if (cx == x)
				ft_putchar('\n');
		}
		cx = 0;
	}
}
