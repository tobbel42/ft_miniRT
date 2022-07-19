/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 08:17:39 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/22 15:17:25 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input: Integer value representing a char									  */
/* Return: Integer, 0 for FALSE, 1 for TRUE									  */
/* 																			  */
/* This function checks if the given character is printable.				  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (TRUE);
	else
		return (FALSE);
}
