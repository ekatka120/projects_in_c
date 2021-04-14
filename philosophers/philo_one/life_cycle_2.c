/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:40:51 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 17:16:53 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_1.h"

void	taking_forks(t_all *all)
{
	if (all->phil_num % 2 == 1)
		pthread_mutex_lock(&(all->mutex_array)[all->left_fork]);
	else
		pthread_mutex_lock(&(all->mutex_array)[all->right_fork]);
	print_life(all, "has taken forks");
	if (all->phil_num % 2 == 0)
		pthread_mutex_lock(&(all->mutex_array)[all->left_fork]);
	else
		pthread_mutex_lock(&(all->mutex_array)[all->right_fork]);
	print_life(all, "has taken forks");
}

void	returning_forks(t_all *all)
{
	pthread_mutex_unlock(&(all->mutex_array)[all->left_fork]);
	pthread_mutex_unlock(&(all->mutex_array)[all->right_fork]);
}

int		philosopher_death(t_all **alls, int x)
{
	pthread_mutex_lock(&(alls[0]->mutex_array)[alls[0]->num + 1]);
	print_time(alls[0]);
	ft_putstr_fd("philosopher ", 1);
	ft_putnbr_fd(x + 1, 1);
	ft_putendl_fd(" is dead", 1);
	return (0);
}
