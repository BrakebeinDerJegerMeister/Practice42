/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:54:24 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/05 11:13:17 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next_list;
	t_list	*my_list;

	if (!begin_list)
		return ;
	my_list = begin_list;
	while (my_list)
	{
		next_list = my_list->next;
		if (my_list->data)
			free_fct(data);
		free(my_list);
		my_list = next_list;
	}
}
