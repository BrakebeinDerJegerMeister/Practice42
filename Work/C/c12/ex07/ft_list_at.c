/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:29:58 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/05 11:47:51 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

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
