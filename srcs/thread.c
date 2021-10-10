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

void	*death_func(void *philo_m)
{
	t_thread **philo;
	philo = philo_m;
	int count = 0;
	long 	life_time = 0;
	int 	count_gorged_philo = 0;

	while (1)
	{
		if ((*philo)[count].time_start_eat)
			life_time = time_now() - (*philo)[count].time_start_eat; // сколько живет филосов сейчас
		else
			life_time = time_now() - (*philo)[count].time_start_thread;

		if ((*philo)[count].gorged)
		{
			(*philo)[count].gorged = false;
			count_gorged_philo++;
		}
		if (count_gorged_philo == (*philo)[count].nbs_phils && (*philo)[count].nbs_eating != 0)
		{
//			printf("наелись\n");
			exit (1);
		}
		if (life_time > (long)(*philo)[count].t_die)
		{

			pthread_mutex_lock(&philo[count]->mutex[(*philo)->nbs_eating]);
			printf("%ld %d died\n", time_now() -(*philo)[count].time_start_thread, (*philo)[count].philo_id);
//			pthread_mutex_unlock(&philo[count]->mutex[(*philo)->nbs_eating]);

//			pthread_mutex_lock(&philo[count]->mutex[(*philo)->left_fork]);
//			exit (1);
			return (NULL);
		}
		count++;
		if (count == (*philo)[0].nbs_phils)
			count = 0;
	}
}

void	*ft_func(void *philo_m)
{
	t_thread	*philo;
	long 		life_time;

	philo = philo_m;
	while(1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		life_time = time_now() - philo->time_start_eat;
//		pthread_mutex_lock(&philo->mutex[philo->nbs_phils]);
//		pthread_mutex_lock(&philo->mutex[philo->nbs_phils]);
		if (life_time > (long)philo->t_die)
		{

			ft_putstr("pup\n");
			return (NULL);
		}
	}
}

int	thread(t_data *all)
{
	int count;

	count = 0;
	while (count < all->nbs_phils)
	{
		all->philo[count].time_start_thread = time_now();
		pthread_create(&all->philo[count].t, NULL, ft_func,  &all->philo[count]);
		count += 2;
		usleep(50);
	}

	count = 1;
	while (count < all->nbs_phils)
	{
		all->philo[count].time_start_thread = time_now();
		pthread_create(&all->philo[count].t, NULL, ft_func,  &all->philo[count]);
		count += 2;
		usleep(50);
	}

	pthread_create(&all->philo[all->nbs_phils].t, NULL, death_func,  &all->philo);
//	count = 0;
//	while (count < all->nbs_phils) {
//		pthread_join(all->philo[count].t, NULL);
//		count++;
//	}
	pthread_join(all->philo[all->nbs_phils].t, NULL);
	return (1);
}
