/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:13:28 by radelwar          #+#    #+#             */
/*   Updated: 2022/01/06 17:13:51 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//	**********************	//
//		libraries			//
//	**********************	//
# include <stdlib.h>
# include <unistd.h>

//	**********************	//
//		definitions			//
//	**********************	//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

//	**********************	//
//		structs				//
//	**********************	//

//	**********************	//
//		c_files				//
//	**********************	//

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*new_buffer(char *buf, unsigned int start);
char	*add_str(char *s1, char const *s2, unsigned int len);
int		count_chars(char *buf);

#endif