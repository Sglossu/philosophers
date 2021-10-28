/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:54:50 by sglossu           #+#    #+#             */
/*   Updated: 2021/10/14 20:54:52 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	life_of_time(t_thread *philo, int count)
{
	(void)count;
	long	life_time;

	life_time = 0;
	if (philo->time_start_eat) {
		life_time = time_now() - philo->time_start_eat;
	}
	else {
		life_time = time_now() - philo->time_start_thread;
	}
	return (life_time);
}

void	count_gorged(t_data *all, int count)
{
	if (all->philo[count].gorged)
	{
		all->philo[count].gorged = false;
		all->count_gorged_philo++;
	}
}