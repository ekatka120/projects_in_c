/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:40:59 by dskittri          #+#    #+#             */
/*   Updated: 2020/07/26 15:03:19 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_spec_pnt_p2(char *parser, char *my_numb, int len)
{
	if (parser[0] == 1)
	{
		ft_put_n_char_fd('0', parser[3] - len, 1);
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(my_numb, 1);
		if (parser[2] > parser[3])
			ft_put_n_char_fd(' ', parser[2] - parser[3], 1);
	}
	else
	{
		if (parser[1] == 1)
		{
			ft_put_n_char_fd('0', parser[2] - len, 1);
			ft_putstr_fd("0x", 1);
			ft_putstr_fd(my_numb, 1);
		}
		else
		{
			if (parser[2] > parser[3])
				ft_put_n_char_fd(' ', parser[2] - parser[3], 1);
			ft_put_n_char_fd('0', parser[3] - len, 1);
			ft_putstr_fd("0x", 1);
			ft_putstr_fd(my_numb, 1);
		}
	}
}

int			ft_spec_pnt(va_list argptr, char *parser)
{
	char	*pointer;
	int		len;
	char	*my_numb;

	pointer = va_arg(argptr, char *);
	if (!(my_numb = ft_itoa_hex_sm((long unsigned int)pointer)))
		return (-1);
	len = ft_strlen(my_numb) + 2;
	if (parser[3] < len)
		parser[3] = len;
	if (parser[2] < len)
		parser[2] = len;
	ft_spec_pnt_p2(parser, my_numb, len);
	free(my_numb);
	my_numb = NULL;
	if (parser[3] > parser[2])
		return (parser[3]);
	return (parser[2]);
}
