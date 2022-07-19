/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 09:58:10 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/22 18:56:53 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: int value of an ASCII character c								  */
/* Return: int value of an ASCII character									  */
/* 																			  */
/* This function returns the ASCII value of the uppercase letter, if c was	  */
/* an lowercase letter. Otherwise it returns the same value as input c.		  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (TRUE);
	else
		return (FALSE);
}

int	ft_toupper(int c)
{
	if (ft_islower(c) == TRUE)
		return (c + 'A' - 'a');
	else
		return (c);
}
