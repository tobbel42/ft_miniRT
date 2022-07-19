/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:56:11 by radelwar          #+#    #+#             */
/*   Updated: 2021/09/14 09:28:18 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	if (!s)
		return (0);
	if (*s != '\0')
		return (1 + ft_strlen(++s));
	else
		return (0);
}

char	*new_buffer(char *buf, unsigned int start)
{
	char			*new_buf;
	unsigned int	c_chars;

	c_chars = 0;
	while (buf[start + c_chars])
		c_chars++;
	new_buf = malloc(sizeof(char) * (c_chars + 1));
	c_chars = 0;
	while (buf[start + c_chars])
	{
		new_buf[c_chars] = buf[start + c_chars];
		c_chars++;
	}
	new_buf[c_chars] = '\0';
	if (buf)
		free(buf);
	return (new_buf);
}

char	*add_str(char *s1, char const *s2, unsigned int len)
{
	char			*ptr_str;
	unsigned int	c_ptr_str;
	unsigned int	c_s;

	c_s = 0;
	ptr_str = malloc(sizeof(char) * (ft_strlen(s1) + len + 1));
	if (ptr_str == NULL)
		return (NULL);
	c_ptr_str = 0;
	while (s1 && s1[c_s] != '\0')
		ptr_str[c_ptr_str++] = s1[c_s++];
	c_s = 0;
	while (s2 && s2[c_s] != '\0' && len > 0)
	{
		ptr_str[c_ptr_str++] = s2[c_s++];
		len--;
	}
	ptr_str[c_ptr_str] = '\0';
	if (s1)
		free(s1);
	return (ptr_str);
}

int	count_chars(char *buf)
{
	int	c_chars;

	c_chars = 0;
	while ((buf[c_chars] != '\0') && (buf[c_chars] != '\n'))
		c_chars++;
	return (c_chars);
}
