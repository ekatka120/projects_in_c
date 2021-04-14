/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:55:05 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 13:27:39 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_2.h"

int					main(int argc, char **argv)
{
	t_all			**alls;
	int				*start_eating;
	int				*is_feed;
	t_all			tmp;

	if (argc != 5 && argc != 6)
		return (error(0));
	if ((alls = parsing(argc, argv)) == NULL)
		return (1);
	if (memory_allocation_2(alls, &start_eating, &is_feed) == 1)
		return (1);
	g_threads = malloc(sizeof(pthread_t) * (alls[0]->num + 1));
	if (g_threads == NULL)
		return (exec_error(1));
	if (sem_opening(alls, &tmp) == -1)
		return (exec_error(1));
	thread_execution_2(alls, start_eating, is_feed);
	thread_checking_2(alls, is_feed);
	sem_closing(&tmp);
	return (0);
}
