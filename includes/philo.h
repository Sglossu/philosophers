/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:13:06 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/09 21:30:03 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_thread
{
    pthread_t		t;
    int				philo_id;
    int				left_fork;
    int				right_fork;
    int				t_die;
    int				t_eat;
    int				t_sleep;
    long 			time_start_eat;
	pthread_mutex_t *mutex;
	long 			time_start_thread;
//	long 			time_start_program;
	int 			nbs_phils;
	int				nbs_eating;
	int 			count_eating;
	bool			gorged;
}               t_thread;

typedef	struct s_data
{
	pthread_mutex_t *table;
	int         	nbs_phils;
	int         	t_die;
	int         	t_eat;
	int         	t_sleep;
	int				nbs_eating;
	int         	c; // delete
	t_thread    	*philo;
//	long 			time_start_program;
}				t_data;

void	errors(char *str);
void	valid_arguments(int argc, char **argv, t_data *ph);
void	init_struct(t_data *all, char **argv, int argc);
int		ft_atoi(const char *str);
void	thread(t_data *all);
long	time_now(void);
void	eating(t_thread *philo);
void	sleeping(t_thread *philo);
void	thinking(t_thread *philo);

void	*death_func(void *philo_m);
void	my_usleep(long time);

#endif 