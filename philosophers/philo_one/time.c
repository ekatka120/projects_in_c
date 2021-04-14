/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:15:18 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 11:15:47 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_1.h"

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
