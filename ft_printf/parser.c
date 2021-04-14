/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:40:59 by dskittri          #+#    #+#             */
/*   Updated: 2020/07/26 15:03:19 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_parser_p2(char *string, va_list argptr, char *parser, int i)
{
	if (string[i] == '.')
		i++;
	else
	{
		if (string[i] == '*')
			parser[2] = va_arg(argptr, int);
		else
			parser[2] = ft_atoi(&string[i]);
		if (parser[2] < 0)
		{
			parser[2] = parser[2] * (-1);
			parser[0] = 1;
		}
	}
	return (i);
}

void		ft_parser_p1(char *string, va_list argptr, char *parser, int i)
{
	int		point;

	if (i != find_spec(string))
	{
		i = ft_parser_p2(string, argptr, parser, i);
		point = ft_strchr_sp1(string, '.', string[find_spec(string)]);
		if (point != -1)
		{
			if (string[point + 1] == '*')
				parser[3] = va_arg(argptr, int);
			else
				parser[3] = ft_atoi(&string[point + 1]);
			if (parser[3] < 0)
				parser[3] = -1;
		}
	}
}

char		*ft_parser(char *string, va_list argptr)
{
	char	*parser;
	int		i;

	if (!(parser = (char *)calloc(4, sizeof(int))))
		return (0);
	i = 0;
	while (ft_strchr("-0+# ", string[i]))
	{
		if (string[i] == '-')
			parser[0] = 1;
		else if (string[i] == '0')
			parser[1] = 1;
		i++;
	}
	parser[2] = -1;
	parser[3] = -1;
	ft_parser_p1(string, argptr, parser, i);
	if (parser[0] == 1)
		parser[1] = 0;
	if (parser[3] != -1)
		parser[1] = 0;
	return (parser);
}
