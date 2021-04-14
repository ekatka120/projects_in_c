/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:44:18 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 16:02:15 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_3.h"

int			start_eating_fullfill(t_all **alls, int x)
{
	int		start_eating;

	sem_wait(alls[0]->data_race);
	start_eating = *(alls[x]->start_eating);
	sem_post(alls[0]->data_race);
	return (start_eating);
}
