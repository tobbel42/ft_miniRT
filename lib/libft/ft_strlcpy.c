/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:14:42 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/25 08:38:14 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to string destination dst								  */
/* Input 2: pointer to string source src									  */
/* Input 3: size_t dstsize for maximum number of moved characters			  */
/* Return: size_t with length of string src 								  */
/* 																			  */
/* String copy size bounded (l) copies up to dstsize - 1 characters from 	  */
/* source to dst. The new destination string will be NULL terminated.		  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	length;

	length = 0;
	while (dstsize > 1 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		length++;
		dstsize--;
	}
	if (dstsize > 0)
	{
		*dst = '\0';
	}
	while (*src != '\0')
	{
		src++;
		length++;
	}
	return (length);
}
