/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:29:29 by radelwar          #+#    #+#             */
/*   Updated: 2021/11/03 17:54:36 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelnode(t_list **list, t_list *del_node, void (*del)(void*))
{
	t_list	*prev;
	t_list	*node;

	if (!list || !(*list) || !del_node)
		return ;
	if (*list == del_node)
	{
		*list = del_node->next;
		ft_lstdelone(del_node, del);
		return ;
	}
	prev = NULL;
	node = *list;
	while (node && node != del_node)
	{
		prev = node;
		node = node->next;
	}
	if (node == del_node)
	{
		prev->next = del_node->next;
		ft_lstdelone(del_node, del);
	}
}
