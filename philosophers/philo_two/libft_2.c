/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:21:03 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 17:24:15 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_2.h"

size_t		ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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
