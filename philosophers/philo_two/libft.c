/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:07:21 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 17:21:46 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_2.h"

void				ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

int					ft_atoi(const char *str)
{
	int				i;
	long int		sign;
	long int		result;

	result = 0;
	sign = 1;
	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') &&
			str[i] != '\0')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

void				ft_putstr_fd(char *s, int fd)
{
	int				i;

	if (fd >= 0)
	{
		i = 0;
		while (s[i] != 0)
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

void				ft_putnbr_fd(int n, int fd)
{
	long long int	num;

	if (fd >= 0)
	{
		num = (long long int)n;
		if (num < 0)
		{
			ft_putchar_fd('-', fd);
			num = num * (-1);
		}
		if (num >= 10)
		{
			ft_putnbr_fd(num / 10, fd);
		}
		num = num % 10;
		ft_putchar_fd(num + '0', fd);
	}
}

void				ft_putendl_fd(char *s, int fd)
{
	if (fd >= 0)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}
