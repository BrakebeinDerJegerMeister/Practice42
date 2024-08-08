/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:41:11 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/06 11:35:35 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

void	swap_datas(t_list *a, t_list *b)
{
	void	*c;

	c = a->data;
	a->data = b->data;
	b->data = c;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		max;
	int		i;
	int		swapped;
	t_list	*list_ptr;
	t_list	*other_list_ptr;

	max = ft_list_size(*begin_list);
	swapped = 1;
	while (swapped && max > 1)
	{
		i = 0;
		swapped = 0;
		list_ptr = *begin_list;
		while (i++ < (max - 1))
		{
			other_list_ptr = list_ptr->next;
			if ((*cmp)(list_ptr->data, other_list_ptr->data) > 0)
			{
				swap_datas(list_ptr, other_list_ptr);
				swapped = 1;
			}
			list_ptr = list_ptr->next;
		}
		max--;
	}
}
