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

long	life_of_time(t_thread **philo, int count)
{
	long	life_time;

	if ((*philo)[count].time_start_eat)
		life_time = time_now() - (*philo)[count].time_start_eat;
	else
		life_time = time_now() - (*philo)[count].time_start_thread;
	return (life_time);
}

int	count_gorged(t_thread **philo, int count, int count_gorged_philo)
{
	if ((*philo)[count].gorged)
	{
		(*philo)[count].gorged = false;
		count_gorged_philo++;
	}
	return (count_gorged_philo);
}

int	countings(int count, t_thread **philo)
{
	count++;
	if (count == (*philo)[0].nbs_phils)
		count = 0;
	return (count);
}
