/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:40:51 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/16 16:30:56 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_3.h"

void	taking_forks(t_all *all)
{
	sem_wait(all->waiting);
	sem_wait(all->forks);
	print_life(all, "has taken forks");
	sem_wait(all->forks);
	print_life(all, "has taken forks");
	sem_post(all->waiting);
}

void	returning_forks(t_all *all)
{
	sem_post(all->forks);
	sem_post(all->forks);
}
