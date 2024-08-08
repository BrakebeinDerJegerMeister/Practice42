/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:26:33 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/07 12:39:51 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	t_btree	*res;

	if (!root)
		return (NULL);
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root);
	res = btree_search_item(root->left, data_ref, cmpf);
	if (!res)
		res = btree_search_item(root->right, data_ref, cmpf);
	return (res);
}
