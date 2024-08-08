/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:25:16 by kaos              #+#    #+#             */
/*   Updated: 2024/08/06 15:56:17 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	insert_elem(t_list **begin_list, t_list *elem, int (*cmp)())
{
	t_list	*prev;
	t_list	*current;

	current = *begin_list;
	prev = NULL;
	if (!current)
		*begin_list = elem;
	while (current)
	{
		if ((*cmp)(data, current->data) > 0)
			break ;
		prev = current;
		current = current->next;
	}
	elem->next = current;
	if (prev)
		prev->next = elem;
	else
		*begin_list = elem;
}

void	ft_sorted_list_merge(t_list **begin_list1,
			t_list *begin_list2, int (*cmp)())
{
	t_list	*next;

	if (!begin_list2 || !*begin_list2)
		return ;
	while (begin_list2)
	{
		next = begin_list2->next;
		insert_elem(begin_list1, begin_list2, cmp);
		begin_list2 = next;
	}
}
