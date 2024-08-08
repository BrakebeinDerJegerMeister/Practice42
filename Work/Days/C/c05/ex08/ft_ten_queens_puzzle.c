/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:43:53 by kaos              #+#    #+#             */
/*   Updated: 2024/07/20 00:18:08 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_queens(int *queens)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = queens[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	no_conflict(int *queens, int col)
{
	int	i;
	int	delta;

	i = 0;
	while (col > 0 && i < col)
	{
		delta = col - i;
		if (queens[i] == queens[col])
			return (0);
		if (queens[i] + delta == queens[col])
			return (0);
		if (queens[i] - delta == queens[col])
			return (0);
		i++;
	}
	return (1);
}

void	seek_solutions(int *queens, int col, int row, int *nb)
{
	if (row == 10)
		return ;
	if (col == 10)
	{
		*nb += 1;
		display_queens(queens);
		return ;
	}
	queens[col] = row;
	if (no_conflict(queens, col))
	{
		seek_solutions(queens, col + 1, 0, nb);
	}
	seek_solutions(queens, col, row + 1, nb);
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	nb;

	nb = 0;
	seek_solutions(queens, 0, 0, &nb);
	return (nb);
}

/*#include <stdio.h>

int	main(void)
{
	printf("\nsolutions : {%d}\n", ft_ten_queens_puzzle());
	return (0);
}*/
