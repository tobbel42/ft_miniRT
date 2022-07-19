/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:18:54 by radelwar          #+#    #+#             */
/*   Updated: 2022/01/18 14:15:59 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/* 																			  */
/* Input: Char pointer to a string											  */
/* Return: double															  */
/* 																			  */
/* ASCII to double creates from the input string an double value.			  */
/* Maximum one + or - sign is allowed in front of the integer.				  */
/* The calculation of the integer stops with the first non digit character.	  */
/* 																			  */
/* ************************************************************************** */
double	ft_atod(const char *str)
{
	double	number;
	int		negative;
	double	exp;

	negative = 1;
	number = 0.0;
	if (*str == '-' || *str == '+')
		negative = 44 - *str++;
	while (ft_isdigit(*str) == TRUE && *str != '\0')
		number = number * 10 + *str++ - '0';
	if (*str == '.')
		str++;
	exp = 0.1;
	while (ft_isdigit(*str) == TRUE && *str != '\0')
	{
		number = number + ((*str++ - '0') * exp);
		exp /= 10;
	}
	return (negative * number);
}
