/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:40:59 by dskittri          #+#    #+#             */
/*   Updated: 2020/04/30 15:03:19 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		*assign(int len_s1, const char *s1, char *pointer)
{
	int			i;

	i = 0;
	while (i != len_s1)
	{
		pointer[i] = s1[i];
		i++;
	}
	return (0);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	size_t		i;
	char		*pointer;

	if (s1 && s2)
	{
		len_s1 = ft_strlen((char *)s1);
		len_s2 = ft_strlen((char *)s2);
		pointer = (char *)malloc(len_s1 + len_s2 + 1);
		if (pointer == 0)
			return (0);
		assign(len_s1, s1, pointer);
		i = 0;
		while (i != len_s2)
		{
			pointer[i + len_s1] = s2[i];
			i++;
		}
		pointer[i + len_s1] = '\0';
		return (pointer);
	}
	return (0);
}
