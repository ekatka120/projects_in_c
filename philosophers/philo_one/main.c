/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:55:05 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 11:13:40 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_1.h"

int					exec_error(int num)
{
	if (num == 1)
		ft_putendl_fd("Execution error", 1);
	return (1);
}

int					main(int argc, char **argv)
{
	t_all			**alls;
	int				*start_eating;
	int				*is_feed;
	pthread_mutex_t	*mutex_array;

	if (argc != 5 && argc != 6)
		return (error(0));
	if ((alls = parsing(argc, argv)) == NULL)
		return (1);
	if (memory_allocation(alls, &start_eating, &is_feed, &mutex_array) == 1)
		return (1);
	g_threads = malloc(sizeof(pthread_t) * (alls[0]->num + 1));
	if (g_threads == NULL)
		return (exec_error(1));
	mutex_initialization(mutex_array, alls[0]);
	thread_execution(alls, start_eating, is_feed, mutex_array);
	thread_checking(alls, is_feed);
	mutex_destruction(mutex_array, alls[0]);
	return (0);
}
