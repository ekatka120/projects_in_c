/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:40:59 by dskittri          #+#    #+#             */
/*   Updated: 2020/07/26 15:03:19 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	int i;

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

void	ft_putchar_fd(unsigned int c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_put_n_char_fd(char c, int n, int fd)
{
	int count;

	count = 0;
	while (count != n)
	{
		ft_putchar_fd(c, fd);
		count++;
	}
}

void	ft_put_n_str_fd(char *str, int n, int fd)
{
	int count;

	count = 0;
	while (count != n)
	{
		ft_putchar_fd(str[count], fd);
		count++;
	}
}

void	ft_putnbr_fd(int n, int fd)
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
