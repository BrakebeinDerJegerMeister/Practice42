/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:37:59 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/05 09:50:42 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*n_list;

	if (!begin_list)
		return (begin_list);
	n_list = begin_list;
	while (n_list->next)
	{
		n_list = n_list->next;
	}
	return (n_list);
}
