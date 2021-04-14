/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:40:59 by dskittri          #+#    #+#             */
/*   Updated: 2020/07/26 15:03:19 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t		ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int			len_unsign(size_t i)
{
	int				n;

	n = 1;
	while (i >= 10)
	{
		n++;
		i = i / 10;
	}
	return (n);
}

int			len16(long unsigned int i)
{
	int				n;

	n = 1;
	if (i < 0)
		n++;
	while (i >= 16)
	{
		n++;
		i = i / 16;
	}
	return (n);
}

int			len_num(int i)
{
	int				n;

	n = 1;
	if (i < 0)
		n++;
	while (i >= 10 || i <= -10)
	{
		n++;
		i = i / 10;
	}
	return (n);
}
