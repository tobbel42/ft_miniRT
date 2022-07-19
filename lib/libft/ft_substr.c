/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:32:38 by radelwar          #+#    #+#             */
/*   Updated: 2022/01/06 19:22:55 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to string s												  */
/* Input 2: unsigned int start												  */
/* Input 3: size_t length len												  */
/* Return: pointer to the new string										  */
/* 			empty string if length of s is less than start					  */
/* 			NULL if malloc failed											  */
/* 																			  */
/* This function creates a new string, starting at start, with the length of  */
/* len.																		  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_null_str(void)
{
	char	*ptr_substr;

	ptr_substr = (char *)my_malloc(sizeof(char));
	if (ptr_substr == NULL)
		return (NULL);
	*ptr_substr = '\0';
	return (ptr_substr);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*ptr_substr;
	unsigned int	counter;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_null_str());
	if (ft_strlen(s) < (start + len))
		len = ft_strlen(s) - start;
	ptr_substr = (char *)my_malloc(sizeof(char) * (len + 1));
	if (ptr_substr == NULL)
		return (NULL);
	counter = 0;
	while (len > counter)
	{
		ptr_substr[counter] = s[start + counter];
		counter++;
	}
	ptr_substr[counter] = '\0';
	return (ptr_substr);
}
