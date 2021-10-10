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
	pthread_mutex_lock(&philo->mutex[philo->nbs_phils]);
	printf("%ld %d has taken a left fork %d\n", time_now() - philo->time_start_thread, philo->philo_id, philo->left_fork);
	pthread_mutex_unlock(&philo->mutex[philo->nbs_phils]);
	if (philo->nbs_phils == 1)
	{
		pthread_mutex_lock(&philo->mutex[philo->nbs_phils]);
		printf("%ld %d died\n", time_now() - philo->time_start_thread, philo->philo_id);
		pthread_mutex_unlock(&philo->mutex[philo->nbs_phils]);
		exit (-1);
	}
	pthread_mutex_lock(&philo->mutex[philo->right_fork]);
	printf("%ld %d has taken a right fork %d\n", time_now() - philo->time_start_thread, philo->philo_id, philo->right_fork);
	pthread_mutex_unlock(&philo->mutex[philo->nbs_phils]);
	philo->time_start_eat = time_now();
	pthread_mutex_lock(&philo->mutex[philo->nbs_phils]);
	printf("%ld %d is eating\n", time_now()- philo->time_start_thread, philo->philo_id);
	pthread_mutex_unlock(&philo->mutex[philo->nbs_phils]);
	my_usleep(philo->t_eat);
	pthread_mutex_unlock(&philo->mutex[philo->left_fork]);
	pthread_mutex_unlock(&philo->mutex[philo->right_fork]);
	philo->count_eating++;
	if (philo->count_eating == philo->nbs_eating && philo->nbs_eating != 0)
		philo->gorged = true;
}

void	sleeping(t_thread *philo)
{
	pthread_mutex_lock(&philo->mutex[philo->nbs_phils]);
	printf("%ld %d is sleeping\n", time_now() - philo->time_start_thread, philo->philo_id);
	pthread_mutex_unlock(&philo->mutex[philo->nbs_phils]);

	my_usleep(philo->t_sleep);
}

void	thinking(t_thread *philo)
{
	pthread_mutex_lock(&philo->mutex[philo->nbs_phils]);
	printf("%ld %d is thinking\n", time_now() - philo->time_start_thread, philo->philo_id);
	pthread_mutex_unlock(&philo->mutex[philo->nbs_phils]);
}
