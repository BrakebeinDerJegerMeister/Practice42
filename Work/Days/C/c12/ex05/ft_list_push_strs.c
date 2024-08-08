/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:17:15 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/05 10:45:14 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*my_list;
	t_list	*tmp_list;

	my_list = NULL;
	i = 0;
	while (i < size)
	{
		tmp_list = ft_create_elem(strs[i]);
		tmp_list->next = my_list;
		my_list = tmp_list;
		i++;
	}
	return (my_list);
}
