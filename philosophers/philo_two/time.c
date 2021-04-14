/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:51:53 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 13:26:45 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_2.h"

int		error(int num)
{
	if (num == 0)
		ft_putendl_fd("Incorrect number of arguments", 1);
	else if (num == 1)
		ft_putendl_fd("Incorrect argument", 1);
	return (1);
}

int		time_now(void)
{
	struct timeval	tv1;
	int				res;

	gettimeofday(&tv1, NULL);
	res = tv1.tv_sec * 1000000 + tv1.tv_usec;
	return (res);
}

int		time_since_begin(t_all *all)
{
	struct timeval	tv1;
	int				res;

	gettimeofday(&tv1, NULL);
	res = tv1.tv_sec * 1000000 + tv1.tv_usec;
	return (res - all->start_time);
}

void	print_time(t_all *all)
{
	ft_putnbr_fd(time_since_begin(all) / 1000, 1);
	ft_putstr_fd("\t", 1);
}
