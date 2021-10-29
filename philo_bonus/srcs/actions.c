/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 23:14:20 by sglossu           #+#    #+#             */
/*   Updated: 2021/10/08 23:14:22 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_thread *philo)
{
	sem_wait(philo->forks);
	message("has taken a left fork", philo);
	if (philo->nbs_phils == 1)
		philo->ph_die = true;
	sem_wait(philo->forks);
	message("has taken a right fork", philo);
	philo->time_start_eat = time_now();
	message("is eating", philo);
	my_usleep(philo->t_eat);
	sem_post(philo->forks);
	sem_post(philo->forks);
	philo->count_eating++;
}

void	sleeping(t_thread *philo)
{
	message("is sleeping", philo);
	my_usleep(philo->t_sleep);
}

void	thinking(t_thread *philo)
{
	message("is thinking", philo);
}
