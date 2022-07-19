/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:09:47 by radelwar          #+#    #+#             */
/*   Updated: 2022/01/06 19:22:15 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to the content of the new node							  */
/* Return: new node															  */
/* 																			  */
/* This function creates a new node with the given content.					  */
/* The pointer to next is set to NULL.										  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = (t_list *)my_malloc(sizeof(t_list));
	if (new_element == NULL)
		return (NULL);
	if (content == NULL)
		new_element->content = NULL;
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}
