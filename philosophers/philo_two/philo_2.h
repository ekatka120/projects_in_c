/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <dskittri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:12:33 by dskittri          #+#    #+#             */
/*   Updated: 2021/01/18 17:23:44 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_2_H
# define PHILO_2_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdlib.h>

pthread_t			*g_threads;

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
	sem_t			*forks;
	sem_t			*print;
	sem_t			*waiting;
	sem_t			*data_race;
	char			*forks_ch;
	char			*print_ch;
	char			*waiting_ch;
	char			*data_race_ch;
}					t_all;

t_all				**parsing(int argc, char **argv);
int					error(int num);
int					time_now(void);
int					time_since_begin(t_all *all);
void				print_time(t_all *all);

int					memory_allocation_2(t_all **alls, int **start_eating,
						int **is_feed);
void				thread_fulfillment_2(t_all **alls, int *start_eating,
						int *is_feed);
void				thread_execution_2(t_all **alls, int *start_eating,
						int *is_feed);
int					thread_checking_2(t_all **alls, int *is_feed);
void				*philo_life_2(void *all_void);
void				print_life(t_all *all, char *str);
void				eating(t_all *all);
void				sleeping(t_all *all);
void				thinking(t_all *all);
int					philosopher_death(t_all **alls, int x);
void				returning_forks(t_all *all);
void				taking_forks(t_all *all);
void				sem_closing(t_all *tmp);
int					sem_opening(t_all **alls, t_all *tmp);
void				fill_all_with_sem(t_all **alls, t_all *tmp);
t_all				**parsing_error(int i);
int					exec_error(int num);
int					ft_atoi(const char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_strdup(const char *s1);

#endif
