/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:18:54 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/25 08:07:46 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input: Char pointer to a string											  */
/* Return: integer															  */
/* 																			  */
/* ASCII to integer creates from the input string an integer value.			  */
/* Maximum one + or - sign is allowed in front of the integer.				  */
/* The calculation of the integer stops with the first non digit character.	  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	number;
	int	negative;

	negative = 1;
	number = 0;
	while ((*str >= 8 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
	{
		negative = -1;
		str++;
	}
	else
	{
		if (*str == '+')
			str++;
	}
	while (ft_isdigit(*str) == TRUE && *str != '\0')
	{
		number = number * 10 + *str - '0';
		str++;
	}
	return (negative * number);
}
