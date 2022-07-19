/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 08:12:27 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/22 15:16:39 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input: Integer value representing a char									  */
/* Return: Integer, 0 for FALSE, 1 for TRUE									  */
/* 																			  */
/* This function checks if the given character is in the ASCII range.		  */
/* The range is from 0 to 127.												  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (TRUE);
	else
		return (FALSE);
}
