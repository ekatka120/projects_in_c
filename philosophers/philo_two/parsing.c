/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:52:00 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 11:53:01 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_2.h"

t_all		**clear_alls(t_all **alls)
{
	int		x;

	x = 0;
	while (alls[x] != NULL)
	{
		free(alls[x]);
		x++;
	}
	free(alls);
	return (parsing_error(2));
}

t_all		**all_fullfillment(t_all all, t_all **alls)
{
	int		x;

	x = 0;
	while (x != all.num)
	{
		alls[x] = malloc(sizeof(t_all));
		if (alls[x] == NULL)
			clear_alls(alls);
		alls[x]->phil_num = x;
		alls[x]->right_fork = x;
		if (alls[x]->phil_num == all.num - 1)
			alls[x]->left_fork = 0;
		else
			alls[x]->left_fork = x + 1;
		alls[x]->num = all.num;
		alls[x]->time_die = all.time_die;
		alls[x]->time_eat = all.time_eat;
		alls[x]->time_sleep = all.time_sleep;
		alls[x]->num_to_eat = all.num_to_eat;
		x++;
	}
	return (alls);
}

t_all		**parsing_error(int i)
{
	if (i == 1)
		ft_putendl_fd("Incorrect argument", 1);
	else if (i == 2)
		ft_putendl_fd("Parsing error", 1);
	return (NULL);
}

t_all		**parsing(int argc, char **argv)
{
	t_all	**alls;
	t_all	all;

	all.num = ft_atoi(argv[1]);
	all.time_die = ft_atoi(argv[2]) * 1000;
	all.time_eat = ft_atoi(argv[3]) * 1000;
	all.time_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
	{
		all.num_to_eat = ft_atoi(argv[5]);
		if (all.num_to_eat <= 0)
			return (parsing_error(1));
	}
	else
		all.num_to_eat = -1;
	if (all.num <= 1 || all.time_die <= 0 || all.time_eat <= 0 ||
			all.time_sleep <= 0)
		return (parsing_error(1));
	alls = malloc(sizeof(t_all *) * (all.num + 1));
	if (alls == NULL)
		return (parsing_error(2));
	return (all_fullfillment(all, alls));
}
