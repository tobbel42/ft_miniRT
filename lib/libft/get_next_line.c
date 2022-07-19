/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:13:09 by radelwar          #+#    #+#             */
/*   Updated: 2021/09/14 09:28:25 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_all(char **buf, char **ret_str)
{
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
	if (*ret_str)
	{
		free(*ret_str);
		*ret_str = NULL;
	}
}

char	*read_new_buf(char *buf, char *ret_str, int *readon, int fd)
{
	int	bytes_read;

	if (buf)
		free(buf);
	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
	{
		free_all(&buf, &ret_str);
		return (NULL);
	}
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free_all(&buf, &ret_str);
		return (NULL);
	}
	buf[bytes_read] = '\0';
	if (bytes_read < BUFFER_SIZE)
		*readon = 0;
	return (buf);
}

char	*append_ret_str(char *ret_str, char **buf, int c_chars)
{
	ret_str = add_str(ret_str, *buf, c_chars);
	if (ft_strlen(ret_str) == 0)
	{
		free_all(buf, &ret_str);
		return (NULL);
	}
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
	return (ret_str);
}

char	*read_file(char **buf, char *ret_str, int readon, int fd)
{
	int	c_chars;

	while (readon)
	{
		if (ft_strlen(*buf) == 0)
		{
			*buf = read_new_buf(*buf, ret_str, &readon, fd);
			if (!(*buf))
				return (NULL);
		}
		c_chars = count_chars(*buf);
		if ((*buf)[c_chars] == '\n')
		{
			ret_str = add_str(ret_str, *buf, c_chars + 1);
			*buf = new_buffer(*buf, c_chars + 1);
			return (ret_str);
		}
		if ((*buf)[c_chars] == '\0')
		{
			ret_str = append_ret_str(ret_str, buf, c_chars);
			if (!ret_str)
				return (NULL);
		}
	}
	return (ret_str);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*ret_str;
	int			readon;

	if (fd < 0)
	{
		return (NULL);
	}
	ret_str = NULL;
	readon = 1;
	return (read_file(&buf, ret_str, 1, fd));
}
