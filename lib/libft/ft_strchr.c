/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:16:37 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/25 08:35:59 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to string s												  */
/* Input 2: integer value of ASCII character c								  */
/* Return: pointer to substring												  */
/* 			NULL if no character c occurs in string s						  */
/* 																			  */
/* String search looks for the first occurence of character c in string s and */
/* returns a pointer to this position.										  */
/* To find the last occurence use ft_strrchr.								  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char) c && *s != '\0')
	{
		s++;
	}
	if (*s == (char) c)
		return ((char *)s);
	else
		return (NULL);
}
