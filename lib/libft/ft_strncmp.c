/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:00:52 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/25 08:39:16 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to string s1											  */
/* Input 2: pointer to string s2											  */
/* Input 3: size_t n for maximum characters to compare						  */
/* Return: int value for difference between the ASCII values				  */
/* 			0 if both strings are the same									  */
/* 																			  */
/* String compare compares up to n characters of both strings and stops at the*/
/* first difference. It returns the difference in the ASCII values.			  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2 && n > 1 && *s1 != '\0')
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
