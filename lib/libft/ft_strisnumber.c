/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:04:44 by radelwar          #+#    #+#             */
/*   Updated: 2021/11/05 19:39:10 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisnumber(char *str)
{
	int	is_number;

	is_number = 1;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			is_number = 0;
			break ;
		}
		str++;
	}
	return (is_number);
}
