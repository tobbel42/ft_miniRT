/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:25:36 by radelwar          #+#    #+#             */
/*   Updated: 2021/11/04 18:26:54 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_malloc.h"

t_malloc	*get_malloc_lst(void)
{
	static t_malloc	lst_head = {NULL};

	return (&lst_head);
}

void	my_free(void *content)
{
	t_malloc	*prev_node;
	t_malloc	*node;
	t_malloc	*search;

	if (!content)
		return ;
	search = content - sizeof(t_malloc);
	prev_node = get_malloc_lst();
	node = prev_node->next;
	while (node && node != search)
	{
		prev_node = node;
		node = node->next;
	}
	if (node == search)
	{
		prev_node->next = node->next;
		free(search);
	}
}

void	my_malloc_free_all(void)
{
	t_malloc	*node;

	node = get_malloc_lst();
	while (node->next)
	{
		my_free(node->next + 1);
	}
}

void	*my_malloc(size_t size)
{
	void		*new_ptr;
	t_malloc	*new_node;
	t_malloc	*node;

	new_node = malloc(sizeof(t_malloc) + size);
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	node = get_malloc_lst();
	while (node->next)
		node = node->next;
	node->next = new_node;
	new_ptr = new_node + 1;
	return (new_ptr);
}

void	*my_malloc_protected(size_t size)
{
	void	*new_ptr;

	new_ptr = my_malloc(size);
	if (!new_ptr)
	{
		my_malloc_free_all();
		exit(EXIT_FAILURE);
	}
	return (new_ptr);
}
