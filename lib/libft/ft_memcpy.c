/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:51:53 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/25 08:33:17 by radelwar         ###   ########.fr       */
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
/* Memory copy copies n characters from the source to the destination.		  */
/* source and destination shouldn't overlap -> better use ft_memmove		  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_cache;

	if (!dst && !src)
		return (NULL);
	dst_cache = dst;
	while (n > 0)
	{
		*(char *)dst++ = *(char *)src++;
		n--;
	}
	return (dst_cache);
}
