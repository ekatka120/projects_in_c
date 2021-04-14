/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:48:31 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 15:35:21 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_2.h"

void		fill_all_with_sem(t_all **alls, t_all *tmp)
{
	int		i;

	i = 0;
	while (i != alls[0]->num)
	{
		alls[i]->forks = tmp->forks;
		alls[i]->print = tmp->print;
		alls[i]->waiting = tmp->waiting;
		alls[i]->data_race = tmp->data_race;
		i++;
	}
}

int			sem_opening(t_all **alls, t_all *tmp)
{
	if ((tmp->forks_ch = ft_strdup("forks")) == NULL)
		return (-1);
	if ((tmp->print_ch = ft_strdup("print")) == NULL)
		return (-1);
	if ((tmp->waiting_ch = ft_strdup("waiting")) == NULL)
		return (-1);
	if ((tmp->data_race_ch = ft_strdup("data_race")) == NULL)
		return (-1);
	sem_unlink(tmp->forks_ch);
	sem_unlink(tmp->print_ch);
	sem_unlink(tmp->waiting_ch);
	sem_unlink(tmp->data_race_ch);
	tmp->forks = sem_open(tmp->forks_ch, O_CREAT, 777, alls[0]->num);
	tmp->print = sem_open(tmp->print_ch, O_CREAT, 777, 1);
	tmp->waiting = sem_open(tmp->waiting_ch, O_CREAT, 777, 1);
	tmp->data_race = sem_open(tmp->data_race_ch, O_CREAT, 777, 1);
	if (tmp->forks == SEM_FAILED || tmp->print == SEM_FAILED ||
			tmp->waiting == SEM_FAILED || tmp->data_race == SEM_FAILED)
		return (-1);
	fill_all_with_sem(alls, tmp);
	return (0);
}

void		sem_closing(t_all *tmp)
{
	free(tmp->forks_ch);
	free(tmp->print_ch);
	free(tmp->waiting_ch);
	free(tmp->data_race_ch);
}
