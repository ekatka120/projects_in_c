/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:40:59 by dskittri          #+#    #+#             */
/*   Updated: 2020/07/26 15:03:19 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_strdup(const char *s1)
{
	size_t	len;
	char	*p;
	size_t	i;

	len = ft_strlen((char*)s1);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	i = 0;
	while (i != len + 1)
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}

void		*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*p;

	i = 0;
	p = (void *)malloc(count * size);
	if (p == NULL)
		return (0);
	while (i != count * size)
	{
		((char *)p)[i] = 0;
		i++;
	}
	return (p);
}

int			ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

char		*ft_strchr(const char *str, int c)
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

int			ft_strchr_sp1(const char *s, int c, char sp)
{
	int		counter;
	char	*s1;

	counter = 0;
	s1 = (char *)s;
	while (s1[counter] && s1[counter] != sp && s1[counter] != c)
		counter++;
	if (s1[counter] == (unsigned char)c)
		return (counter);
	return (-1);
}
