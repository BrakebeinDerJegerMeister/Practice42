/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:26:50 by kaos              #+#    #+#             */
/*   Updated: 2024/08/08 19:32:49 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_corner(int cx, int cy, int x, int y)
{
	if (cx == 1 && (cy == 1 || cy == y))
		ft_putchar('A');
	if (cx > 1 && cx == x && (cy == 1 || cy == y))
		ft_putchar('C');
}

void	print_other(int cx, int cy, int x, int y)
{
	if (((cx == 1 || cx == x) && (cy > 1 && cy < y))
		|| ((cx > 1 && cx < x) && (cy == 1 || cy == y)))
		ft_putchar('B');
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
