/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:44:18 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 15:42:57 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_2.h"

int			exec_error(int num)
{
	if (num == 1)
		ft_putendl_fd("Execution error", 1);
	return (1);
}

int			memory_allocation_2(t_all **alls, int **start_eating, int **is_feed)
{
	*start_eating = malloc(sizeof(int) * (alls[0]->num + 1));
	if (*start_eating == NULL)
		return (exec_error(1));
	memset(*start_eating, 0, alls[0]->num + 1);
	*is_feed = malloc(sizeof(int) * (alls[0]->num + 1));
	if (*is_feed == NULL)
		return (exec_error(1));
	memset(*is_feed, 0, alls[0]->num + 1);
	return (0);
}

int			start_eating_fullfill(t_all **alls, int x)
{
	int		start_eating;

	sem_wait(alls[0]->data_race);
	start_eating = *(alls[x]->start_eating);
	sem_post(alls[0]->data_race);
	return (start_eating);
}

int			thread_checking_2(t_all **alls, int *is_feed)
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
			if (number_of_feed == alls[0]->num)
				return (0);
			if (time_after_eating > alls[x]->time_die && is_feed[x] == 0)
				return (philosopher_death(alls, x));
			if (is_feed[x] == 1)
				number_of_feed++;
			x++;
		}
		if (number_of_feed == alls[0]->num)
			return (0);
	}
}
