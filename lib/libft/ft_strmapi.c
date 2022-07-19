/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:12:59 by radelwar          #+#    #+#             */
/*   Updated: 2022/01/06 19:22:47 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to string destination dst								  */
/* Input 2: pointer to function f											  */
/* Return: pointer to new string											  */
/* 			NULL if malloc failed											  */
/* 																			  */
/* This function uses the function f on every character of string s.		  */
/* Space for the return string is malloced.									  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	char	*new_str_save;
	int		counter;

	if (!s || !f)
		return (NULL);
	counter = 0;
	new_str = (char *)my_malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new_str == NULL)
		return (NULL);
	new_str_save = new_str;
	while (s[counter] != '\0')
	{
		*new_str = f(counter, s[counter]);
		new_str++;
		counter++;
	}
	*new_str = '\0';
	return (new_str_save);
}
