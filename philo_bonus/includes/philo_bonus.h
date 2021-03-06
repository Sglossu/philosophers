/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:13:06 by sglossu           #+#    #+#             */
/*   Updated: 2021/10/31 03:06:58 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_thread
{
	pthread_t		t;
	int				philo_id;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	long			time_start_eat;
	sem_t			*forks;
	sem_t			*print;
	pid_t			pid;
	long			time_start_thread;
	long			time_start_program;
	int				nbs_phils;
	int				nbs_eating;
	int				count_eating;
	bool			ph_die;
}				t_thread;

typedef struct s_data
{
	int				nbs_phils;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nbs_eating;
	long			time_start_program;
	sem_t			*forks;
	sem_t			*print;
	t_thread		*philo;
}				t_data;

int		valid_arguments(int argc, char **argv, t_data *ph);
int		init_struct(t_data *all, char **argv, int argc);
int		ft_atoi(const char *str);
void	thread(t_data *all);
long	time_now(void);
void	eating(t_thread *philo);
void	sleeping(t_thread *philo);
void	thinking(t_thread *philo);
void	ft_putstr(char *s);
void	my_usleep(long time);
void	message(char *str, t_thread *philo);
long	life_of_time(t_thread *philo);
void	ft_putnbr_long(long n);
void	ft_putchar(char c);
void	ft_putstr(char *s);

#endif
