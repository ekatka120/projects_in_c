/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:16:17 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 11:55:36 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_2.h"

void	philo_life_2_2(t_all *all)
{
	eating(all);
	returning_forks(all);
	sleeping(all);
	thinking(all);
}

void	*philo_life_2(void *all_void)
{
	t_all		*all;
	int			eating_times;
	int			start_eating;

	all = (t_all *)all_void;
	eating_times = 0;
	sem_wait(all->data_race);
	start_eating = all->start_time;
	all->start_eating = &start_eating;
	sem_post(all->data_race);
	while (eating_times != all->num_to_eat)
	{
		taking_forks(all);
		sem_wait(all->data_race);
		start_eating = time_now();
		all->start_eating = &start_eating;
		sem_post(all->data_race);
		philo_life_2_2(all);
		eating_times++;
	}
	*(all->is_feed) = 1;
	while (1)
		usleep(1000000);
	return (NULL);
}
