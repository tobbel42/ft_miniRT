/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:55:09 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/25 09:08:41 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: void pointer to the string s									  */
/* Input 2: character c to detect											  */
/* Input 3: maximum number of characters of the memory to check				  */
/* Return: pointer to the first occurence of c in the string s,				  */
/* 			NULL if not found												  */
/* 																			  */
/* Memory search searches in a length of n in the memory for the character c. */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*work_s;

	work_s = (unsigned char *)s;
	while (n > 0 && *work_s != (unsigned char) c)
	{
		work_s++;
		n--;
	}
	if (n > 0)
		return ((void *)work_s);
	return (NULL);
}
