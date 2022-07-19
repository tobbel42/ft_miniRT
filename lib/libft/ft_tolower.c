/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:11:15 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/22 18:56:36 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: int value of an ASCII character c								  */
/* Return: int value of an ASCII character									  */
/* 																			  */
/* This function returns the ASCII value of the lowercase letter, if c was	  */
/* an uppercase letter. Otherwise it returns the same value as input c.		  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (TRUE);
	else
		return (FALSE);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c) == TRUE)
		return (c + 'a' - 'A');
	else
		return (c);
}
