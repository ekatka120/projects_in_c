/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:41:24 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 15:56:00 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_1.h"

void	philo_life_2(t_all *all)
{
	eating(all);
	returning_forks(all);
	sleeping(all);
	thinking(all);
}

void	*philo_life(void *all_void)
{
	t_all		*all;
	int			eating_times;
	int			start_eating;

	all = (t_all *)all_void;
	eating_times = 0;
	pthread_mutex_lock(&(all->mutex_array)[all->num + 2]);
	start_eating = all->start_time;
	all->start_eating = &start_eating;
	pthread_mutex_unlock(&(all->mutex_array)[all->num + 2]);
	while (eating_times != all->num_to_eat)
	{
		taking_forks(all);
		pthread_mutex_lock(&(all->mutex_array)[all->num + 2]);
		start_eating = time_now();
		all->start_eating = &start_eating;
		pthread_mutex_unlock(&(all->mutex_array)[all->num + 2]);
		philo_life_2(all);
		eating_times++;
	}
	*(all->is_feed) = 1;
	while (1)
		usleep(1000000);
	return (NULL);
}

void	mutex_initialization(pthread_mutex_t *mutex_array, t_all *all)
{
	int	x;

	x = 0;
	while (x != all->num + 3)
	{
		pthread_mutex_init(&mutex_array[x], NULL);
		x++;
	}
}

void	mutex_destruction(pthread_mutex_t *mutex_array, t_all *all)
{
	int	x;

	x = 0;
	while (x != all->num + 3)
	{
		pthread_mutex_destroy(&mutex_array[x]);
		x++;
	}
}
