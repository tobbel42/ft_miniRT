/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:48:33 by radelwar          #+#    #+#             */
/*   Updated: 2022/01/06 19:22:10 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input: integer value														  */
/* Return: pointer to a string												  */
/* 																			  */
/* Integer to ASCII creates a string out of the integer value				  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_write_nbr(int n, int sign, char *write_str)
{
	int		digit;
	char	*write_pos;

	if (n > 9 || n < -9)
	{
		digit = n % 10;
		write_pos = ft_write_nbr(n / 10, sign, write_str);
		*write_pos = (digit * sign) + '0';
		return (++write_pos);
	}
	if (n < 0)
	{
		*write_str = '-';
		write_str++;
	}
	*write_str = (n * sign) + '0';
	return (++write_str);
}

char	*ft_itoa(int n)
{
	int		n_save;
	int		count_digits;
	char	*str_nbr;
	int		sign;

	n_save = n;
	count_digits = 1;
	while (n > 9 || n < -9)
	{
		count_digits++;
		n /= 10;
	}
	if (n < 0)
		count_digits++;
	str_nbr = (char *)my_malloc(sizeof(char) * (count_digits + 1));
	if (!str_nbr)
		return (NULL);
	str_nbr[count_digits] = '\0';
	sign = 1;
	if (n_save < 0)
		sign = -1;
	ft_write_nbr(n_save, sign, str_nbr);
	return (str_nbr);
}
