/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 10:55:42 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/23 17:31:50 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to the head of a linked list							  */
/* Input 2: pointer to a function to use on every node's content			  */
/* Return: pointer to the head of a newly created linked list				  */
/* 																			  */
/* This function creates a new linked list out of the given list.			  */
/* Every node's content is modified with the given function.				  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*my_list;
	t_list	*new_node;

	if (!lst)
		return (NULL);
	my_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&my_list, del);
			return (NULL);
		}
		if (!(new_node->content))
		{
			ft_lstclear(&my_list, del);
			return (NULL);
		}
		ft_lstadd_back(&my_list, new_node);
		lst = lst->next;
	}
	return (my_list);
}
