/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:22:58 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/09 21:30:53 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_func(void *philo_m)
{
	t_thread *philo;
	philo = philo_m;
	int count = 0;

	while (1){

	}
}

void	*ft_func(void *philo_m)
{
	t_thread	*philo;
	long		time;

	time = time_now();
	philo = philo_m;
	pthread_mutex_lock(&philo->mutex[philo->left_fork]);
	printf("%d has taken the left fork\n", philo->philo_id);
	pthread_mutex_lock(&philo->mutex[philo->right_fork]);
	printf("%d has taken the right fork\n", philo->philo_id);
	printf("%d is eating\n", philo->philo_id);
	time = time_now();
	usleep(philo->t_eat * 1000);
	pthread_mutex_unlock(&philo->mutex[philo->left_fork]);
	pthread_mutex_unlock(&philo->mutex[philo->right_fork]);

	printf("%d is sleeping\n", philo->philo_id);
//	printf("1sleep: %ld\n", time_now());
	usleep(philo->t_sleep * 1000);
//	printf("2sleep: %ld\n", time_now());
	// если время еще есть - он будет думать
	return (0);
}

void	thread(t_data *all)
{
	int count = 0;

	pthread_create(&all->philo[all->nbs_phils].t, NULL, death_func,  &all->philo[all->nbs_phils]); // поток для контроля смерти
	while (count < all->nbs_phils) {
		pthread_create(&all->philo[count].t, NULL, ft_func,  &all->philo[count]);
		count++;
	}
	count = 0;
	while (count < all->nbs_phils) {
		pthread_join(all->philo[count].t, NULL);
		count++;
	}
}