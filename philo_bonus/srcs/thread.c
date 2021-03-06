/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:22:58 by sglossu           #+#    #+#             */
/*   Updated: 2021/10/31 03:05:55 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*func(void *philo_m)
{
	t_thread	*philo;
	long		life_time;

	philo = philo_m;
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		life_time = time_now() - philo->time_start_eat;
		if (life_time > (long)philo->t_die)
		{
			message("died", philo);
			exit (-1);
		}
	}
}

void	child(t_data *all, int count)
{
	long		life_time;

	all->philo[count].time_start_thread = time_now();
	all->philo[count].time_start_program = all->time_start_program;
	pthread_create(&all->philo[count].t, NULL, func, &all->philo[count]);
	while (1)
	{
		life_time = life_of_time(&all->philo[count]);
		if ((all->philo[count].count_eating == all->nbs_eating + 2 && \
		all->nbs_eating != 0))
		{
			usleep(50);
			exit (1);
		}
		if (life_time > (long)all->t_die || all->philo[count].ph_die)
		{
			message("died", &all->philo[count]);
			exit (1);
		}
	}
}

void	thread(t_data *all)
{
	int	count;

	count = 0;
	all->time_start_program = time_now();
	while (count < all->nbs_phils)
	{
		all->philo[count].pid = fork();
		usleep(50);
		if (all->philo[count].pid == 0)
		{
			child(all, count);
			exit(1);
		}
		count++;
	}
	count = 0;
	waitpid(0, NULL, 0);
	count = 0;
	while (count < all->nbs_phils)
	{
		kill(all->philo[count].pid, SIGKILL);
		count++;
	}
}
