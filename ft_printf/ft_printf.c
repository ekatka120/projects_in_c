/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:40:59 by dskittri          #+#    #+#             */
/*   Updated: 2020/07/26 15:03:19 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_spec_p1(char *string, va_list argptr, char *parser, int i)
{
	int		result;

	result = 0;
	if (string[i] == 's')
		result = ft_spec_string(argptr, parser);
	else if (string[i] == 'i' || string[i] == 'd')
		result = ft_spec_int(argptr, parser);
	else if (string[i] == 'u')
		result = ft_spec_unsig(argptr, parser);
	else if (string[i] == 'x')
		result = ft_spec_hex_sm(argptr, parser);
	else if (string[i] == 'X')
		result = ft_spec_hex_bg(argptr, parser);
	else if (string[i] == 'p')
		result = ft_spec_pnt(argptr, parser);
	else if (string[i] == 'c')
		result = ft_spec_char(argptr, parser);
	else if (string[i] == '%')
		result = ft_spec_per(parser);
	return (result);
}

int			ft_spec(char *string, va_list argptr)
{
	int		i;
	int		result;
	char	*parser;

	i = find_spec(&string[1]) + 1;
	result = 0;
	if (i == 0)
		return (-1);
	if (!(parser = ft_parser(&string[1], argptr)))
		return (-1);
	result = ft_spec_p1(string, argptr, parser, i);
	free(parser);
	parser = NULL;
	return (result);
}

int			ft_printf_p1(char *string, va_list argptr, int count, int i)
{
	int		start;
	int		ret_count;

	while (string[i] != '\0')
	{
		start = i;
		while ((string[i] != '%') && (string[i] != '\0'))
			ft_putchar_fd(string[i++], 1);
		count += i - start;
		if (string[i] == '\0')
			return (count);
		ret_count = ft_spec(&string[i], argptr);
		if (ret_count == -1)
			return (-1);
		count += ret_count;
		i = i + 2 + find_spec(&string[i + 1]);
	}
	return (count);
}

int			ft_printf(char *string, ...)
{
	va_list	argptr;
	int		count;

	va_start(argptr, string);
	count = ft_printf_p1(string, argptr, 0, 0);
	va_end(argptr);
	return (count);
}
