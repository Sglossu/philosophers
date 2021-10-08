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
//	if (philo->count_eating == philo->nbs_eating)

	pthread_mutex_lock(&philo->mutex[philo->left_fork]);
	if (philo->nbs_phils != 1)
		pthread_mutex_lock(&philo->mutex[philo->right_fork]);
	philo->time_start_eat = time_now();


//	printf("%d time to start eat %ld\n", philo->philo_id, philo->time_start_eat);
//	printf("%d time to start thread %ld\n", philo->philo_id, philo->time_start_thread);

	printf("%ld %d has taken a fork\n", philo->time_start_eat - philo->time_start_thread, philo->philo_id);
	printf("%ld %d is eating\n", philo->time_start_eat - philo->time_start_thread, philo->philo_id);

	my_usleep(philo->t_eat);
	pthread_mutex_unlock(&philo->mutex[philo->left_fork]);
	if (philo->nbs_phils != 1)
		pthread_mutex_unlock(&philo->mutex[philo->right_fork]);
	philo->count_eating++;
	if (philo->count_eating == philo->nbs_eating && philo->nbs_eating != 0)
		philo->gorged = true;
}

void	sleeping(t_thread *philo)
{
	printf("%ld %d is sleeping\n", time_now() - philo->time_start_thread, philo->philo_id);
	//	printf("1sleep: %ld\n", time_now());
	my_usleep(philo->t_sleep);
}

void	thinking(t_thread *philo)
{
	printf("%ld %d is thinking\n", time_now() - philo->time_start_thread, philo->philo_id);
//	my_usleep(philo->t_die - philo->t_sleep - philo->t_eat); // пока 2 800 300 300 - время на подумать 200 // удалить
//	philo->time_start_thread = time_now();
}
