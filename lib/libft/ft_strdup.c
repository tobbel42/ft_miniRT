/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:06:38 by radelwar          #+#    #+#             */
/*   Updated: 2022/01/06 19:22:37 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to string s1											  */
/* Return: pointer to string duplicate										  */
/* 			NULL if malloc failed											  */
/* 																			  */
/* String duplicate duplicates string s1 and stores it in a malloced space.	  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*ptr_work;

	ptr = my_malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr_work = ptr;
	while (*s1 != '\0')
	{
		*ptr_work = *s1;
		ptr_work++;
		s1++;
	}
	*ptr_work = '\0';
	return (ptr);
}
