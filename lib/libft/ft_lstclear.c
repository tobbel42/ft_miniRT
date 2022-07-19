/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:12:43 by radelwar          #+#    #+#             */
/*   Updated: 2021/11/04 16:36:07 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to the head of a linked list							  */
/* Input 2: pointer to a function to delete the node's content				  */
/* Return: void																  */
/* 																			  */
/* This function deletes the whole list.									  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	if (*lst == NULL)
		return ;
	if ((*lst)->content != NULL)
		del((*lst)->content);
	ft_lstclear(&((*lst)->next), del);
	my_free(*lst);
	*lst = NULL;
}
