/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:40:51 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 17:18:22 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_2.h"

void		thread_fulfillment_2(t_all **alls, int *start_eating, int *is_feed)
{
	int		x;
	int		start_time;

	x = 0;
	start_time = time_now();
	while (x != alls[0]->num)
	{
		alls[x]->start_eating = &start_eating[x];
		alls[x]->is_feed = &is_feed[x];
		alls[x]->start_time = start_time;
		x++;
	}
}

void		thread_execution_2(t_all **alls, int *start_eating, int *is_feed)
{
	int		x;

	thread_fulfillment_2(alls, start_eating, is_feed);
	x = 0;
	while (x != alls[0]->num)
	{
		if (!(x % 2))
			pthread_create(&g_threads[x], NULL, philo_life_2, alls[x]);
		x++;
	}
	x = 0;
	while (x != alls[0]->num)
	{
		if (x % 2)
			pthread_create(&g_threads[x], NULL, philo_life_2, alls[x]);
		x++;
	}
	usleep(1000);
}

void		taking_forks(t_all *all)
{
	sem_wait(all->waiting);
	sem_wait(all->forks);
	print_life(all, "has taken forks");
	sem_wait(all->forks);
	print_life(all, "has taken forks");
	sem_post(all->waiting);
}

void		returning_forks(t_all *all)
{
	sem_post(all->forks);
	sem_post(all->forks);
}

int			philosopher_death(t_all **alls, int x)
{
	sem_wait(alls[0]->print);
	print_time(alls[0]);
	ft_putstr_fd("philosopher ", 1);
	ft_putnbr_fd(x + 1, 1);
	ft_putendl_fd(" is dead", 1);
	return (0);
}
