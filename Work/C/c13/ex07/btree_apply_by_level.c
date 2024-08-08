/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:46:51 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/08 13:28:25 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_list	*ft_create_list_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem)
	{
		elem->data = data;
		elem->next = NULL;
	}
	return (elem);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*n_list;

	if (*begin_list)
	{
		n_list = *begin_list;
		while (n_list->next)
			n_list = n_list->next;
		n_list->next = ft_create_list_elem(data);
	}
	else
		*begin_list = ft_create_list_elem(data);
}

void	tree_to_list(t_btree *root, t_list **vlist)
{
	if (!root)
		return ;
	if (!*vlist)
		*vlist = ft_create_list_elem(NULL);
	ft_list_push_back((t_list **)&((*vlist)->data), root);
	tree_to_list(root->left, &((*vlist)->next));
	tree_to_list(root->right, &((*vlist)->next));
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_list	*tree_list;
	t_list	*node_list;
	t_btree	*node;
	int		nb[2];

	if (!root)
		return ;
	tree_list = NULL;
	nb[0] = 0;
	nb[1] = 1;
	tree_to_list(root, &tree_list);
	while (tree_list)
	{
		node_list = (t_list *)tree_list->data;
		while (node_list)
		{
			node = (t_btree *)node_list->data;
			if (node && node->item)
				(*applyf)(node->item, nb[0], nb[1]);
			node_list = node_list->next;
			nb[1] = 0;
		}
		nb[0]++;
		tree_list = tree_list->next;
	}
}
