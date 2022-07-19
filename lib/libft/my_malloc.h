/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:25:48 by radelwar          #+#    #+#             */
/*   Updated: 2022/01/09 18:00:34 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MALLOC_H
# define MY_MALLOC_H

# include "libft.h"

typedef struct s_malloc
{
	struct s_malloc	*next;
}	t_malloc;

void	*my_malloc(unsigned long size);
void	*my_malloc_protected(unsigned long size);
void	my_free(void *ptr);
void	my_malloc_free_all(void);

#endif