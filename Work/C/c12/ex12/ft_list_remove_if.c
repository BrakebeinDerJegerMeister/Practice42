/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:31:27 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/05 14:53:56 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*list_ptr;
	t_list	*prev;

	prev = NULL;
	list_ptr = *begin_list;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
		{
			if (prev)
				prev->next = list_ptr->next;
			else
				*begin_list = list_ptr->next;
			(*free_fct)(list_ptr->data);
			free(list_ptr);
			return ;
		}
		prev = list_ptr;
		list_ptr = list_ptr->next;
	}
}
