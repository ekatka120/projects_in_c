/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:40:59 by dskittri          #+#    #+#             */
/*   Updated: 2020/07/26 15:03:19 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					ft_atoi(const char *str)
{
	int				result;
	int				flag;

	flag = 1;
	result = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if (flag == -1)
		return (result * (-1));
	return (result);
}

char				*ft_itoa(int num)
{
	int				n;
	char			*res;
	int				count;
	long long int	i;

	i = (long long int)num;
	n = len_num(i);
	res = (char *)malloc(n + 1);
	if (res == 0)
		return (0);
	if (i < 0)
	{
		res[0] = '-';
		i = i * (-1);
	}
	count = 1;
	while (i >= 10)
	{
		res[n - count] = i % 10 + '0';
		i = i / 10;
		count++;
	}
	res[n - count] = i + '0';
	res[n] = '\0';
	return (res);
}

char				*ft_itoa_unsigned(unsigned int num)
{
	int				n;
	char			*res;
	int				count;

	n = len_unsign(num);
	res = (char *)malloc(n + 1);
	if (res == 0)
		return (0);
	count = 1;
	while (num >= 10)
	{
		res[n - count] = num % 10 + '0';
		num = num / 10;
		count++;
	}
	res[n - count] = num + '0';
	res[n] = '\0';
	return (res);
}

char				*ft_itoa_hex_sm(long unsigned int num)
{
	int				n;
	char			*res;
	int				count;
	unsigned int	tmp;

	n = len16(num);
	res = (char *)malloc(n + 1);
	if (res == 0)
		return (0);
	count = 1;
	while (num >= 16)
	{
		tmp = num % 16;
		ft_hex_char(tmp, n - count, res, 87);
		num = num / 16;
		count++;
	}
	ft_hex_char(num, n - count, res, 87);
	res[n] = '\0';
	return (res);
}

char				*ft_itoa_hex_bg(unsigned int num)
{
	int				n;
	char			*res;
	int				count;
	unsigned int	tmp;

	n = len16(num);
	res = (char *)malloc(n + 1);
	if (res == 0)
		return (0);
	count = 1;
	while (num >= 16)
	{
		tmp = num % 16;
		ft_hex_char(tmp, n - count, res, 55);
		num = num / 16;
		count++;
	}
	ft_hex_char(num, n - count, res, 55);
	res[n] = '\0';
	return (res);
}
