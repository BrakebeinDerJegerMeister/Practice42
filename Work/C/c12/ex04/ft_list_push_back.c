/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:59:25 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/05 10:08:33 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*n_list;

	if (*begin_list)
	{
		n_list = *begin_list;
		while (n_list->next)
			n_list = n_list->next;
		n_list->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
