/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:05:25 by radelwar          #+#    #+#             */
/*   Updated: 2022/01/06 19:22:32 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to string s												  */
/* Input 2: delimiter character c											  */
/* Return: string array with substrings										  */
/* 			NULL if something failed										  */
/* 																			  */
/* This function splits the string s into substrings, using the delimiter c.  */
/* The delimiter c is deleted in the substrings.							  */
/* 																			  */
/* ************************************************************************** */

#include "libft.h"

static int	ft_error_handling(char const *s, char c, char ***error_str)
{
	int		len_substr;

	*error_str = NULL;
	if (s == NULL)
		return (TRUE);
	if (ft_strlen(s) == 0)
	{
		*error_str = (char **)my_malloc(sizeof(char *) * 1);
		if (*error_str == NULL)
			return (TRUE);
		(*error_str)[0] = NULL;
		return (TRUE);
	}
	if (c == '\0')
	{
		*error_str = (char **)my_malloc(sizeof(char *) * 2);
		if (*error_str == NULL)
			return (TRUE);
		len_substr = ft_strlen(s);
		(*error_str)[0] = ft_substr(s, 0, len_substr);
		(*error_str)[1] = NULL;
		return (TRUE);
	}
	return (FALSE);
}

static int	ft_cnt_substr(char const *s, char c)
{
	int		len_substr;
	int		count_substr;

	count_substr = 0;
	len_substr = 0;
	while (s[len_substr] != '\0')
	{
		while (s[len_substr] == c)
			len_substr++;
		if (s[len_substr] != '\0')
			count_substr++;
		while (s[len_substr] != c && s[len_substr] != '\0')
			len_substr++;
	}
	return (count_substr);
}

static void	ft_split_string(char const *s, char c, char **ar_substr)
{
	int		len_substr;
	int		count_substr;
	int		move_s;

	move_s = 0;
	count_substr = 0;
	while (s[move_s] != '\0')
	{
		while (s[move_s] == c)
			move_s++;
		if (s[move_s] == '\0')
			break ;
		len_substr = 0;
		while (s[len_substr + move_s] != c && s[len_substr + move_s] != '\0')
			len_substr++;
		ar_substr[count_substr] = ft_substr(&s[move_s], 0, len_substr);
		while (s[len_substr + move_s] == c)
			len_substr++;
		count_substr++;
		if (s[move_s + len_substr] == '\0')
			break ;
		move_s = move_s + len_substr;
	}
	ar_substr[count_substr] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**ar_substr;

	ar_substr = NULL;
	if (ft_error_handling(s, c, &ar_substr) == TRUE)
		return (ar_substr);
	ar_substr = (char **)my_malloc(sizeof(char *) * (ft_cnt_substr(s, c) + 1));
	if (ar_substr == NULL)
		return (NULL);
	ft_split_string(s, c, ar_substr);
	return (ar_substr);
}
