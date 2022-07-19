/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 07:48:28 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/25 08:37:41 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to string destination dst								  */
/* Input 2: pointer to string source src									  */
/* Input 3: size_t dstsize for maximum number of moved characters			  */
/* Return: size_t with length of string src plus dstsize;					  */
/* 			maximum: length src plus length dst								  */
/* 																			  */
/* String concatenate size bounded (l) adds the string src to the string dst. */
/* Maximum dstsize - length dst - 1 characters are added.					  */
/* The new destination string will be NULL terminated.						  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length_dst;
	size_t	length_src;
	size_t	counter;

	length_dst = ft_strlen(dst);
	length_src = ft_strlen(src);
	counter = 0;
	if (dstsize < length_dst + 1)
		return (length_src + dstsize);
	else
	{
		while (counter < dstsize - length_dst - 1 && counter <= length_src)
		{
			dst[length_dst + counter] = src[counter];
			counter++;
		}
		dst[length_dst + counter] = '\0';
		return (length_src + length_dst);
	}
}
