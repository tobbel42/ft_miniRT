/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:13:58 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/25 08:34:24 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: void pointer to the destination string							  */
/* Input 2: integer with character c's ASCII value							  */
/* Input 3: number n of characters to write									  */
/* Return: pointer to the destination string								  */
/* 																			  */
/* Memory set writes n times character c to the destination					  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	while (len > 0)
	{
		*str = c;
		str++;
		len--;
	}
	return (b);
}
