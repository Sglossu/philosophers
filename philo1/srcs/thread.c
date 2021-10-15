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

void	*death(void *philo_m)
{
	t_thread	**philo;
	int			count;
	long		life_time;
	int			count_gorged_philo;

	count = 0;
	count_gorged_philo = 0;
	philo = philo_m;
	while (1)
	{
		life_time = life_of_time(philo, count);
		count_gorged_philo = count_gorged(philo, count, count_gorged_philo);
		if ((count_gorged_philo == (*philo)[count].nbs_phils && \
		(*philo)[count].nbs_eating != 0))
		{
			pthread_mutex_lock((*philo)->mutex + (**philo).nbs_phils);
			return (NULL);
		}
		if (life_time > (long)(*philo)[count].t_die || (*philo)[count].ph_die)
		{
			message("died", **philo);
			return (NULL);
		}
		count = countings(count, philo);
	}
}

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

int	thread(t_data *all)
{
	int	count;

	count = 0;
	all->time_start_program = time_now();
	while (count < all->nbs_phils)
	{
		all->philo[count].time_start_thread = time_now();
		all->philo[count].time_start_program = all->time_start_program;
		pthread_create(&all->philo[count].t, NULL, func, &all->philo[count]);
		count += 2;
		usleep(50);
	}
	count = 1;
	while (count < all->nbs_phils)
	{
		all->philo[count].time_start_thread = time_now();
		all->philo[count].time_start_program = all->time_start_program;
		pthread_create(&all->philo[count].t, NULL, func, &all->philo[count]);
		count += 2;
		usleep(50);
	}
	pthread_create(&all->philo[all->nbs_phils].t, NULL, death, &all->philo);
	pthread_join(all->philo[all->nbs_phils].t, NULL);
	return (1);
}
