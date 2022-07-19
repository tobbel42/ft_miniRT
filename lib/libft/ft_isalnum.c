/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:30:12 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/22 15:14:17 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input: Integer value representing a char									  */
/* Return: Integer, 0 for FALSE, 1 for TRUE									  */
/* 																			  */
/* This function checks if the given character is alphanumerical.			  */
/* Alphanumberical means an alphabetical character or a digit.				  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (TRUE);
	else
		return (FALSE);
}
