/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:38:06 by radelwar          #+#    #+#             */
/*   Updated: 2022/01/06 19:22:42 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to string s1											  */
/* Input 2: pointer to string s2											  */
/* Return: pointer to new string											  */
/* 			NULL if malloc failed											  */
/* 																			  */
/* String join merges both strings and stores them in a malloced space.		  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr_str;
	char	*ptr_str_begin;

	if (!s1 || !s2)
		return (NULL);
	ptr_str = my_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen (s2) + 1));
	if (ptr_str == NULL)
		return (NULL);
	ptr_str_begin = ptr_str;
	while (*s1 != '\0')
	{
		*ptr_str = *s1;
		ptr_str++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*ptr_str = *s2;
		ptr_str++;
		s2++;
	}
	*ptr_str = '\0';
	return (ptr_str_begin);
}
