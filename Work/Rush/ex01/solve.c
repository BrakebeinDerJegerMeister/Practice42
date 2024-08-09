/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:56:40 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/09 12:56:26 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_array(int sz, int **array);
int		**create_array(int sz);
int		**copy_array(int sz, int **array);

int	is_duplicated(int sz, int row, int col, int **b)
{
	int	j;
	int	k;
	int	nb;

	j = -1;
	while (++j < (sz - 1))
	{
		k = j;
		while (++k < sz)
		{
			if ((b[row][j] != 0 && b[row][j] == b[row][k])
				|| (b[j][col] != 0 && b[j][col] == b[k][col]))
				return (1);
		}
	}
	return (0);
}

int	is_invalid_row(int sz, int row, int **b, int *in)
{
	int	i;
	int	nb;
	int	left;
	int	right;
	int	max;

	left = in[2 * sz + row];
	right = in[3 * sz + row];


}

int	**solve(int sz, int *in, int **board)
{
}

int	try_solve(int sz, int *in)
{
	int	**board;

	board = create_array(sz);
}
