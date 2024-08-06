/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:32:19 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/06 12:55:34 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;
	t_list	*prev;
	t_list	*current;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
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
	return ;
}
