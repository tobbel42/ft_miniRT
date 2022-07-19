/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:56:41 by radelwar          #+#    #+#             */
/*   Updated: 2021/08/22 16:40:33 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 																			  */
/* Input 1: pointer to string s												  */
/* Input 2: pointer to function f											  */
/* Return: void																  */
/* 																			  */
/* This function goes through the string s and uses the function f on every	  */
/* character.																  */
/* 																			  */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	counter;

	if (!s || !f)
		return ;
	counter = 0;
	while (*s != '\0')
	{
		f(counter, s);
		s++;
		counter++;
	}
}
