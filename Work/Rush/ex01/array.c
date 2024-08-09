/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:33:26 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/09 12:00:22 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_array(int sz, int **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (i < sz)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	**create_array(int sz)
{
	int	**array;
	int	i;
	int	j;

	array = malloc(sizeof(int *) * sz);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < sz)
	{
		array[i] = malloc(sizeof(int) * sz);
		if (array[i] == NULL)
		{
			free_array(--i, array);
			return (NULL);
		}
		j = 0;
		while (j < sz)
		{
			array[i][j] = 0;
			j++;
		}
		i++;
	}
	return (array);
}

int	**copy_array(int sz, int **array)
{
	int	**array_cpy;
	int	i;
	int	j;

	array_cpy = create_array(sz);
	if (array_cpy == NULL)
		return (array_cpy);
	i = 0;
	while (i < sz)
	{
		j = 0;
		while (j < sz)
		{
			array_cpy[i][j] = array[i][j];
			j++;
		}
		i++;
	}
	return (array_cpy);
}
