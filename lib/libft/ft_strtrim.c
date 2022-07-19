/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:53:24 by radelwar          #+#    #+#             */
/*   Updated: 2021/11/04 18:04:43 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to string s1											  */
/* Input 2: pointer to character array set									  */
/* Return: pointer to the new string										  */
/* 			NULL if malloc failed											  */
/* 																			  */
/* String trim removes the characters from set from the beginning and the	  */
/* end of string s1, as long as there are only characters included in set.	  */
/* 																			  */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_delete_front(char const *s1, char const *set)
{
	int	deleted;
	int	cnt_set;

	deleted = TRUE;
	while (deleted == TRUE)
	{
		deleted = FALSE;
		cnt_set = 0;
		while (set[cnt_set] != '\0')
		{
			if (set[cnt_set] == *s1)
			{
				s1++;
				deleted = TRUE;
			}
			cnt_set++;
		}
	}
	return ((char *)s1);
}

static char	*ft_delete_back(char const *s1, char const *set)
{
	int		cnt_s1;
	int		cnt_set;
	int		deleted;
	int		length_trim_str;

	length_trim_str = ft_strlen(s1);
	cnt_s1 = ft_strlen(s1);
	if (cnt_s1 > 0)
		cnt_s1--;
	deleted = TRUE;
	while (deleted == TRUE)
	{
		deleted = FALSE;
		cnt_set = 0;
		while (set[cnt_set] != '\0')
		{
			if (set[cnt_set++] == s1[cnt_s1])
			{
				length_trim_str--;
				cnt_s1--;
				deleted = TRUE;
			}
		}
	}
	return (ft_substr(s1, 0, length_trim_str));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	if (!s1 || !set)
		return (NULL);
	s1 = ft_delete_front(s1, set);
	return (ft_delete_back(s1, set));
}
