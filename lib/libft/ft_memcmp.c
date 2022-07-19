/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:33:02 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/25 08:33:53 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: void pointer to string s1										  */
/* Input 2: void pointer to string s2										  */
/* Input 3: maximum number of characters in the memory to compare			  */
/* Return: difference of the ASCII values on the first differing character,	  */
/* 			0 if both strings are the same									  */
/* 																			  */
/* Memory compare compares n bytes in the memory.							  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s1_work;
	char	*s2_work;

	s1_work = (char *)s1;
	s2_work = (char *)s2;
	if (n == 0)
		return (0);
	while (*s1_work == *s2_work && n > 1)
	{
		s1_work++;
		s2_work++;
		n--;
	}
	return ((unsigned char) *s1_work - (unsigned char) *s2_work);
}
