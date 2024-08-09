/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:32:05 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/09 12:56:37 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int	try_solve(int board_size, int *in);

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 4;
	while (i <= 10)
	{
		if (argc == (i * i + 1))
			break ;
		i++;
	}
	if (i > 9)
		return (-1);
	j = 0;
	while (j < i * i)
	{
		if (argv[i + 1][1] != '\0')
			return (-1);
		if (!(argv[i + 1][0] >= '0' && argv[i + 1][0] <= '9'))
			return (-1);
		j++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int	board_size;
	int	*in;
	int	i;

	board_size = check_args(argc, argv);
	if (board_size == -1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	in = malloc(sizeof(int) * board_size * board_size);
	i = 0;
	ft_putnbr(board_size);
	ft_putchar('\n');
	while (i < board_size * board_size)
	{
		in[i] = argv[i + 1][0] - '0';
		ft_putnbr(in[i]);
		i++;
	}
	ft_putchar('\n');
	if (try_solve(board_size, in) == -1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0)
}
