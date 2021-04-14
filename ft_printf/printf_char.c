/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:40:59 by dskittri          #+#    #+#             */
/*   Updated: 2020/07/26 15:03:19 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_spec_char(va_list argptr, char *parser)
{
	unsigned int	c;

	c = va_arg(argptr, unsigned int);
	if (parser[2] <= 1)
	{
		ft_putchar_fd(c, 1);
		parser[2] = 1;
	}
	else
	{
		if (parser[0] == 1)
		{
			ft_putchar_fd(c, 1);
			ft_put_n_char_fd(' ', parser[2] - 1, 1);
		}
		else
		{
			ft_put_n_char_fd(' ', parser[2] - 1, 1);
			ft_putchar_fd(c, 1);
		}
	}
	return (parser[2]);
}

int		ft_spec_per(char *parser)
{
	unsigned int	c;

	c = '%';
	if (parser[2] <= 1)
	{
		ft_putchar_fd(c, 1);
		parser[2] = 1;
	}
	else
	{
		if (parser[0] == 1)
		{
			ft_putchar_fd(c, 1);
			ft_put_n_char_fd(' ', parser[2] - 1, 1);
		}
		else
		{
			if (parser[1] == 1)
				ft_put_n_char_fd('0', parser[2] - 1, 1);
			else
				ft_put_n_char_fd(' ', parser[2] - 1, 1);
			ft_putchar_fd(c, 1);
		}
	}
	return (parser[2]);
}
