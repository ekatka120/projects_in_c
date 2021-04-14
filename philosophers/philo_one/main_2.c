/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:44:18 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 11:13:40 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_1.h"

void		thread_fulfillment(t_all **alls, int *start_eating, int *is_feed,
			pthread_mutex_t *mutex_array)
{
	int		x;
	int		start_time;

	x = 0;
	start_time = time_now();
	while (x != alls[0]->num)
	{
		alls[x]->start_eating = &start_eating[x];
		alls[x]->is_feed = &is_feed[x];
		alls[x]->mutex_array = mutex_array;
		alls[x]->start_time = start_time;
		x++;
	}
}

void		thread_execution(t_all **alls, int *start_eating, int *is_feed,
			pthread_mutex_t *mutex_array)
{
	int		x;

	thread_fulfillment(alls, start_eating, is_feed, mutex_array);
	x = 0;
	while (x != alls[0]->num)
	{
		if (!(x % 2))
			pthread_create(&g_threads[x], NULL, philo_life, alls[x]);
		x++;
	}
	x = 0;
	while (x != alls[0]->num)
	{
		if (x % 2)
			pthread_create(&g_threads[x], NULL, philo_life, alls[x]);
		x++;
	}
	usleep(1000);
}

int			memory_allocation(t_all **alls, int **start_eating, int **is_feed,
			pthread_mutex_t **mutex_array)
{
	*start_eating = malloc(sizeof(int) * (alls[0]->num + 1));
	if (*start_eating == NULL)
		return (exec_error(1));
	memset(*start_eating, 0, alls[0]->num + 1);
	*is_feed = malloc(sizeof(int) * (alls[0]->num + 1));
	if (*is_feed == NULL)
		return (exec_error(1));
	memset(*is_feed, 0, alls[0]->num + 1);
	*mutex_array = malloc(sizeof(pthread_mutex_t) * (alls[0]->num + 3));
	if (*mutex_array == NULL)
		return (exec_error(1));
	return (0);
}

int			start_eating_fullfill(t_all **alls, int x)
{
	int		start_eating;

	pthread_mutex_lock(&(alls[0]->mutex_array)[alls[0]->num + 2]);
	start_eating = *(alls[x]->start_eating);
	pthread_mutex_unlock(&(alls[0]->mutex_array)[alls[0]->num + 2]);
	return (start_eating);
}

int			thread_checking(t_all **alls, int *is_feed)
{
	int		x;
	int		number_of_feed;
	int		time_after_eating;
	int		start_eating;

	while (1)
	{
		x = 0;
		number_of_feed = 0;
		while (x != alls[0]->num && number_of_feed != alls[0]->num)
		{
			start_eating = start_eating_fullfill(alls, x);
			time_after_eating = time_now() - start_eating;
			if (time_after_eating > alls[x]->time_die && is_feed[x] == 0)
				return (philosopher_death(alls, x));
			if (is_feed[x] == 1)
				number_of_feed++;
			x++;
		}
		if (number_of_feed == alls[0]->num)
			return (0);
		usleep(1000);
	}
}
