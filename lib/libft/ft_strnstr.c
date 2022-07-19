/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:40:17 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/25 08:40:31 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to string haystack										  */
/* Input 2: pointer to string needle										  */
/* Input 3: size_t len for maximum characters to compare					  */
/* Return: pointer to beginning of needle in haystack						  */
/* 			NULL if no needle is found in haystack							  */
/* 																			  */
/* String in string looks in the first len characters of haystack for the	  */
/* needle.																	  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*haystack_begin;
	char	*needle_begin;
	size_t	counter;

	haystack_begin = (char *)haystack;
	needle_begin = (char *)needle;
	if (*needle_begin == '\0')
		return (haystack_begin);
	while (*haystack != '\0' && len > 0)
	{
		counter = len--;
		while (*haystack == *needle && counter > 0)
		{
			haystack++;
			needle++;
			counter--;
			if (*needle == '\0')
			{
				return (haystack_begin);
			}
		}
		needle = needle_begin;
		haystack = ++haystack_begin;
	}
	return (NULL);
}
