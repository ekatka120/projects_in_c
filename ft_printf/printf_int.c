/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:40:59 by dskittri          #+#    #+#             */
/*   Updated: 2020/07/26 15:03:19 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_spec_int_p4(char *parser, int number, char *my_numb, int len)
{
	if (parser[2] > parser[3])
		ft_put_n_char_fd(' ', parser[2] - parser[3], 1);
	if (number < 0)
	{
		ft_putchar_fd('-', 1);
		ft_put_n_char_fd('0', parser[3] - len, 1);
		ft_putstr_fd(&my_numb[1], 1);
	}
	else
	{
		ft_put_n_char_fd('0', parser[3] - len, 1);
		ft_putstr_fd(my_numb, 1);
	}
}

void		ft_spec_int_p3(char *parser, int number, char *my_numb, int len)
{
	if (parser[1] == 1)
	{
		if (number < 0)
		{
			ft_putchar_fd('-', 1);
			ft_put_n_char_fd('0', parser[2] - len, 1);
			ft_putstr_fd(&my_numb[1], 1);
		}
		else
		{
			ft_put_n_char_fd('0', parser[2] - len, 1);
			ft_putstr_fd(my_numb, 1);
		}
	}
	else
		ft_spec_int_p4(parser, number, my_numb, len);
}

void		ft_spec_int_p2(char *parser, int number, char *my_numb, int len)
{
	if (parser[3] < len)
		parser[3] = len;
	if (parser[2] < len)
		parser[2] = len;
	if (parser[0] == 1)
	{
		if (number < 0)
		{
			ft_putchar_fd('-', 1);
			ft_put_n_char_fd('0', parser[3] - len, 1);
			ft_putstr_fd(&my_numb[1], 1);
		}
		else
		{
			ft_put_n_char_fd('0', parser[3] - len, 1);
			ft_putstr_fd(my_numb, 1);
		}
		if (parser[2] > parser[3])
			ft_put_n_char_fd(' ', parser[2] - parser[3], 1);
	}
	else
		ft_spec_int_p3(parser, number, my_numb, len);
}

int			ft_spec_int(va_list argptr, char *parser)
{
	int		number;
	int		len;
	char	*my_numb;

	number = va_arg(argptr, int);
	if (parser[3] == 0 && number == 0)
		my_numb = ft_strdup("");
	else
		my_numb = ft_itoa(number);
	if (my_numb == NULL)
		return (-1);
	len = ft_strlen(my_numb);
	if (number < 0)
		parser[3]++;
	ft_spec_int_p2(parser, number, my_numb, len);
	free(my_numb);
	my_numb = NULL;
	if (parser[3] > parser[2])
		return (parser[3]);
	return (parser[2]);
}
