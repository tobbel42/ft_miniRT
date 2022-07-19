/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:32:39 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/25 08:34:54 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: integer value													  */
/* Input 2: integer value for file descriptor fd							  */
/* Return: void																  */
/* 																			  */
/* Put character uses the write function to write the given integer value	  */
/* to the given file descriptor.											  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write_nbr(int n, int sign, int fd)
{
	char	digit;

	if (n > 9 || n < -9)
	{
		digit = ((n % 10) * sign) + '0';
		ft_write_nbr(n / 10, sign, fd);
		write(fd, &digit, 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
	}
	digit = (n * sign) + '0';
	write(fd, &digit, 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	ft_write_nbr(n, sign, fd);
}
