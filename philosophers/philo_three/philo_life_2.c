/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:30:25 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 17:05:13 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_3.h"

void	print_life(t_all *all, char *str)
{
	sem_wait(all->print);
	print_time(all);
	ft_putstr_fd("philosopher ", 1);
	ft_putnbr_fd(all->phil_num, 1);
	ft_putstr_fd(" ", 1);
	ft_putendl_fd(str, 1);
	sem_post(all->print);
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
	print_life(all, "is thinking");
}
