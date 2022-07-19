/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:34:56 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/25 08:40:43 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to string s												  */
/* Input 2: integer value of ASCII character c								  */
/* Return: pointer to substring												  */
/* 			NULL if no character c occurs in string s						  */
/* 																			  */
/* String search looks for the last occurence of character c in string s and  */
/* returns a pointer to this position.										  */
/* To find the first occurence use ft_strchr.								  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*position;

	position = NULL;
	while (*s != '\0')
	{
		if (*s == (char) c)
			position = (char *)s;
		s++;
	}
	if (*s == (char) c)
		position = (char *)s;
	return (position);
}
