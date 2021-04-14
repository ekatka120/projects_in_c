/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:40:59 by dskittri          #+#    #+#             */
/*   Updated: 2020/07/26 15:03:19 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_spec_string(va_list argptr, char *parser)
{
	char	*str;
	int		len;
	int		count;

	str = va_arg(argptr, char *);
	if (str == 0)
		str = "(null)";
	len = ft_strlen(str);
	if (len > parser[3] && parser[3] != -1)
		len = parser[3];
	if (parser[2] == -1)
		parser[2] = len;
	if (parser[3] == -1)
		parser[3] = len;
	count = ft_spec_string_2(parser, len, str);
	str = NULL;
	return (count);
}

int			ft_spec_string_2(char *parser, int len, char *str)
{
	int		count;

	count = 0;
	if (parser[2] > len)
	{
		if (parser[0] == 0)
		{
			ft_put_n_char_fd(' ', parser[2] - len, 1);
			ft_put_n_str_fd(str, len, 1);
		}
		else
		{
			ft_put_n_str_fd(str, len, 1);
			ft_put_n_char_fd(' ', parser[2] - len, 1);
		}
		count = parser[2];
	}
	else
	{
		ft_put_n_str_fd(str, len, 1);
		count = len;
	}
	return (count);
}
