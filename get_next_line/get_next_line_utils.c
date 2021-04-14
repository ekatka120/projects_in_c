/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 14:40:59 by dskittri          #+#    #+#             */
/*   Updated: 2020/07/03 15:03:19 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strchr(const char *str, int c)
{
	int		i;
	char	*string;

	string = (char *)str;
	i = 0;
	while (*(string + i) != c && *(string + i) != '\0')
		i++;
	if (*(string + i) == '\0' && c != '\0')
		return (0);
	else
		return (string + i);
}

size_t			ft_strlen_sp(char *str, char sp)
{
	size_t		i;

	i = 0;
	while (str[i] != sp)
		i++;
	return (i);
}

size_t			assign(size_t len_s1, char *s1, char *pointer)
{
	size_t		i;

	i = 0;
	while (i != len_s1)
	{
		pointer[i] = s1[i];
		i++;
	}
	return (i);
}

char			*ft_strjoin(char *s1, char *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	size_t		i;
	char		*pointer;

	if (s1 && s2)
	{
		len_s1 = ft_strlen_sp(s1, '\0');
		len_s2 = ft_strlen_sp(s2, '\0');
		pointer = (char *)malloc(len_s1 + len_s2 + 1);
		if (pointer == 0)
			return (0);
		assign(len_s1, s1, pointer);
		i = assign(len_s2, s2, &pointer[len_s1]);
		pointer[i + len_s1] = '\0';
		s1 = 0;
		return (pointer);
	}
	return (0);
}

char			*ft_strdup_sp(char *s1, char sp)
{
	size_t		len;
	char		*p;
	size_t		i;

	len = ft_strlen_sp((char*)s1, sp);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	i = 0;
	while (i != len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
