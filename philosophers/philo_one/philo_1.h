/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:45:27 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 17:13:08 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_1_H
# define PHILO_1_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct		s_all
{
	int				num;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_to_eat;
	int				phil_num;
	int				right_fork;
	int				left_fork;
	int				start_time;
	int				*is_feed;
	int				*start_eating;
	pthread_mutex_t	*mutex_array;
}					t_all;

pthread_t			*g_threads;

t_all				**parsing(int argc, char **argv);
t_all				**parsing_error(int i);
int					exec_error(int num);
int					error(int num);
int					time_now(void);
int					time_since_begin(t_all *all);
void				print_time(t_all *all);
void				mutex_initialization(pthread_mutex_t *mutex_array,
					t_all *all);
void				mutex_destruction(pthread_mutex_t *mutex_array, t_all *all);
void				thread_fulfillment(t_all **alls, int *start_eating,
					int *is_feed, pthread_mutex_t *mutex_array);
void				thread_execution(t_all **alls, int *start_eating,
					int *is_feed, pthread_mutex_t *mutex_array);
int					memory_allocation(t_all **alls, int **start_eating,
					int **is_feed, pthread_mutex_t **mutex_array);
int					thread_checking(t_all **alls, int *is_feed);
int					philosopher_death(t_all **alls, int x);
void				eating(t_all *all);
void				sleeping(t_all *all);
void				thinking(t_all *all);
void				taking_forks(t_all *all);
void				returning_forks(t_all *all);
void				make_dead(t_all *all);
void				*philo_life(void *all_void);
void				print_life(t_all *all, char *str);
int					ft_atoi(const char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);

#endif
