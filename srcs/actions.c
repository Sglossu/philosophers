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
	pthread_mutex_lock(&philo->mutex[philo->left_fork]);
	message("has taken a fork", *philo);
	if (philo->nbs_phils == 1)
	{
		philo->philo_die = true;
		message("died", *philo);
	}
	pthread_mutex_lock(&philo->mutex[philo->right_fork]);
	message("has taken a fork", *philo);
	philo->time_start_eat = time_now();
	message("is eating", *philo);
	my_usleep(philo->t_eat);
	pthread_mutex_unlock(&philo->mutex[philo->left_fork]);
	pthread_mutex_unlock(&philo->mutex[philo->right_fork]);
	philo->count_eating++;
	if (philo->count_eating == philo->nbs_eating && philo->nbs_eating != 0)
		philo->gorged = true;
}

void	sleeping(t_thread *philo)
{
	message("is sleeping", *philo);
	my_usleep(philo->t_sleep);
}

void	thinking(t_thread *philo)
{
	message("is thinking", *philo);
}
