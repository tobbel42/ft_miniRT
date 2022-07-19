/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:23:40 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/22 15:15:38 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input: Integer value representing a char									  */
/* Return: Integer, 0 for FALSE, 1 for TRUE									  */
/* 																			  */
/* This function checks if the given character is an alphabetical character.  */
/* It doesn't care about upper-/lowercase.									  */
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

static int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (TRUE);
	else
		return (FALSE);
}

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (TRUE);
	else
		return (FALSE);
}
