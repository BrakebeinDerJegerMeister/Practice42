/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:37:44 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/08 10:01:31 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	get_level(t_btree *root, int current_level, int *max_level)
{
	if (!root)
		return ;
	if (current_level > *max_level)
		*max_level = current_level;
	get_level(root->left, current_level + 1, max_level);
	get_level(root->right, current_level + 1, max_level);
}

int	btree_level_count(t_btree *root)
{
	int	max_level;

	max_level = 0;
	get_level(root, 1, &max_level);
	return (max_level);
}
