/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:22:58 by sglossu           #+#    #+#             */
/*   Updated: 2021/10/08 23:15:17 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			return (NULL);
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
		life_time = life_of_time(&all->philo[count], count);
		count_gorged(all, count);
		if ((all->count_gorged_philo == all->nbs_phils && \
		all->nbs_eating != 0))
		{
			sem_wait(all->philo[count].print);
			exit (1);
		}
		if (life_time > (long)all->t_die || all->philo[count].ph_die)
		{
			message("died", &all->philo[count]);
			exit (1);
		}
	}
}

void    thread(t_data *all)
{
	int count;

	count = 0;
	all->time_start_program = time_now();
	while (count < all->nbs_phils)
	{
		all->philo[count].pid = fork();
		usleep(500);
		if (all->philo[count].pid == 0)
			child(all, count);
		count += 2;
	}
	count = 1;
	while (count < all->nbs_phils)
	{
		all->philo[count].pid = fork();
		usleep(500);
		if (all->philo[count].pid == 0)
			child(all, count);
		count += 2;
	}
	waitpid(-1, NULL, 0);
	count = 0;
	while (count < all->nbs_phils)
	{
		kill(all->philo[count].pid, SIGKILL);
		count++;
	}
}