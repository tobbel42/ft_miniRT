/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:59:39 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/25 08:33:07 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: void pointer to the destination string							  */
/* Input 2: void pointer to the source string								  */
/* Input 3: number n of characters copy										  */
/* Return: pointer to the destination string								  */
/* 			NULL if wrong input												  */
/* 																			  */
/* Memory move copies n characters from the source to the destination.		  */
/* If n < 1 destination isn't modified.										  */
/* Source and destination can overlap, nothing will be destroied.			  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_work;
	char	*src_work;

	if (!dst && !src)
		return (NULL);
	if (len < 1)
		return (dst);
	dst_work = (char *)dst;
	src_work = (char *)src;
	if (dst > src)
	{
		while (len-- > 0)
			dst_work[len] = src_work[len];
	}
	else
	{
		while (len-- > 0)
		{
			*dst_work = *src_work;
			src_work++;
			dst_work++;
		}
	}
	return (dst);
}
