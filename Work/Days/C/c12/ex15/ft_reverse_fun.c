/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_fun.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:39:24 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/06 12:23:04 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*n_list;

	count = 0;
	n_list = begin_list;
	while (n_list)
	{
		n_list = n_list->next;
		count++;
	}
	return (count);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	count;
	t_list			*n_list;

	count = 0;
	n_list = begin_list;
	while (n_list)
	{
		if (nbr == count)
			return (n_list);
		n_list = n_list->next;
		count++;
	}
	return (NULL);
}

void	swap_datas(t_list *begin_list, unsigned int a, unsigned int b)
{
	void	*data_c;
	t_list	*list_a;
	t_list	*list_b;

	list_a = ft_list_at(begin_list, a);
	list_b = ft_list_at(begin_list, b);
	data_c = list_a->data;
	list_a->data = list_b->data;
	list_b->data = data_c;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int	max;
	int	i;

	max = ft_list_size(begin_list);
	i = 0;
	while (i < (max / 2))
	{
		swap_datas(begin_list, i, max - 1 - i);
		i++;
	}
}
