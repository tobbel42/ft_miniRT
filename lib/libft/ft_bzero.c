/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:33:35 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/25 08:24:18 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: Void pointer to a string										  */
/* Input 2: size_t length len												  */
/* Return: void																  */
/* 																			  */
/* This function sets every element in memory in a length of len to '\0',	  */
/* maximum length characters are set to 0.									  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	char	*str;

	str = b;
	while (len > 0)
	{
		*str = '\0';
		str++;
		len--;
	}
}
