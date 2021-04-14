/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:56:42 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 17:01:37 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_3.h"

int				thread_checking_3(t_all *all, int *is_feed)
{
	int		time_after_eating;
	int		start_eating_stack;

	while (1)
	{
		if (*is_feed == 1)
			exit(1);
		sem_wait(all->data_race);
		start_eating_stack = *all->start_eating;
		time_after_eating = time_now() - start_eating_stack;
		if (time_after_eating > all->time_die && *is_feed == 0)
			return (philosopher_death(all));
		sem_post(all->data_race);
	}
}

void			philosopher(t_all *all)
{
	pthread_t	my_thread;
	int			start_eating;
	int			is_feed;
	char		*data_race;
	sem_t		*sem;

	start_eating = all->start_time;
	is_feed = 0;
	all->start_eating = &start_eating;
	all->is_feed = &is_feed;
	sem_unlink(data_race);
	sem = sem_open(data_race, O_CREAT, 777, 1);
	pthread_create(&my_thread, NULL, philo_life_3, all);
	usleep(100);
	thread_checking_3(all, &is_feed);
}

void			process_creation(t_all *all, int x, pid_t *pid_array)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
		philosopher(all);
	pid_array[x] = pid;
}

void			check_process(t_all **alls, pid_t *pid, int *fork_res, int x)
{
	int		stat;

	while (1)
	{
		waitpid(-1, &stat, WUNTRACED);
		if (WIFEXITED(stat) != 0)
		{
			stat = WEXITSTATUS(stat);
			if (stat == -1 || stat == 255)
				break ;
			if (stat == 1)
				x++;
		}
		if (x == alls[0]->num)
			break ;
	}
	x = 0;
	while (x != alls[0]->num)
	{
		kill(pid[x], SIGKILL);
		x++;
	}
	free(pid);
	free(fork_res);
}
