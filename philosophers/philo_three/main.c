/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:55:05 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 16:52:09 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_3.h"

int			philosopher_death(t_all *all)
{
	sem_wait(all->print);
	print_time(all);
	ft_putstr_fd("philosopher ", 1);
	ft_putnbr_fd(all->phil_num, 1);
	ft_putendl_fd(" is dead", 1);
	exit(-1);
}

void		forking(t_all **alls)
{
	int		x;
	int		*fork_res;
	pid_t	*pid_array;
	int		start_eating;

	x = 0;
	if ((fork_res = malloc(sizeof(int) * (alls[0]->num) + 1)) == NULL)
		exit(1);
	if ((pid_array = malloc(sizeof(pid_t) * (alls[0]->num) + 1)) == NULL)
		exit(1);
	memset(fork_res, 0, alls[0]->num);
	start_eating = time_now();
	while (x != alls[0]->num)
	{
		alls[x]->start_time = start_eating;
		alls[x]->start_eating_prev = start_eating;
		process_creation(alls[x], x, pid_array);
		x++;
	}
	check_process(alls, pid_array, fork_res, 1);
}

int			main(int argc, char **argv)
{
	t_all	**alls;
	t_all	tmp;

	if (argc != 5 && argc != 6)
		return (error(0));
	if ((alls = parsing(argc, argv)) == NULL)
		return (1);
	if (sem_opening(alls, &tmp) == -1)
		return (1);
	forking(alls);
	sem_closing(&tmp);
	return (0);
}
