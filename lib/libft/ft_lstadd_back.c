/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:05:34 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/23 16:29:11 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to the head of a linked list							  */
/* Input 2: new list node													  */
/* Return: void																  */
/* 																			  */
/* This function adds a list node at the tail.								  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL)
		return ;
	if (!new)
		return ;
	if ((*lst) == NULL)
	{
		*lst = new;
		return ;
	}
	if ((*lst)->next == NULL)
	{
		(*lst)->next = new;
		new->next = NULL;
		return ;
	}
	lst = &((*lst)->next);
	ft_lstadd_back(lst, new);
}
