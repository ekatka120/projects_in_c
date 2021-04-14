/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:39:13 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 17:16:33 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_1.h"

void	print_life(t_all *all, char *str)
{
	pthread_mutex_lock(&(all->mutex_array)[all->num + 1]);
	print_time(all);
	ft_putstr_fd("philosopher ", 1);
	ft_putnbr_fd(all->phil_num + 1, 1);
	ft_putstr_fd(" ", 1);
	ft_putendl_fd(str, 1);
	pthread_mutex_unlock(&(all->mutex_array)[all->num + 1]);
}

void	eating(t_all *all)
{
	int	start_eating_time;
	int	time_after_eating;

	print_life(all, "is eating");
	start_eating_time = time_now();
	usleep(all->time_eat * 0.95);
	time_after_eating = (time_now() - start_eating_time);
	while (time_after_eating < all->time_eat)
	{
		usleep(1);
		time_after_eating = (time_now() - start_eating_time);
	}
}

void	sleeping(t_all *all)
{
	int	start_sleeping_time;
	int	time_after_sleeping;

	print_life(all, "is sleeping");
	start_sleeping_time = time_now();
	usleep(all->time_sleep * 0.95);
	time_after_sleeping = (time_now() - start_sleeping_time);
	while (time_after_sleeping < all->time_sleep)
	{
		usleep(1);
		time_after_sleeping = (time_now() - start_sleeping_time);
	}
}

void	thinking(t_all *all)
{
	if (all->num % 2 == 1)
		usleep(0.9 * all->time_eat);
	print_life(all, "is thinking");
}
