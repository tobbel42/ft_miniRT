/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:46:52 by radelwar          #+#    #+#             */
/*   Updated: 2022/01/09 18:00:18 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: number of elements												  */
/* Input 2: length of one element											  */
/* Return: Void pointer to malloced space									  */
/* 																			  */
/* This function mallocs space for the given number of elements.			  */
/* The whole space is filled with '\0'.										  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = my_malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	*ft_calloc_protected(size_t count, size_t size)
{
	void	*ptr;

	ptr = my_malloc_protected(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
