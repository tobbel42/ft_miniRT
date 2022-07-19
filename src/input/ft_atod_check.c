/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:51:06 by skienzle          #+#    #+#             */
/*   Updated: 2022/01/18 18:27:46 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_atod_check(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (FALSE);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0' || str[i] < '0' || str[i] > '9')
		return (FALSE);
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		i++;
	if (str[i] == '.')
	{
		i++;
		if (str[i] == '\0' || str[i] < '0' || str[i] > '9')
			return (FALSE);
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		i++;
	if (str[i] != '\0' && str[i] != '\n')
		return (FALSE);
	return (TRUE);
}
