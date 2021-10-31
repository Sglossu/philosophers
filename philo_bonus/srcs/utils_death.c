/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:54:50 by sglossu           #+#    #+#             */
/*   Updated: 2021/10/31 03:05:57 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	life_of_time(t_thread *philo)
{
	long	life_time;

	life_time = 0;
	if (philo->time_start_eat)
	{
		life_time = time_now() - philo->time_start_eat;
	}
	else
	{
		life_time = time_now() - philo->time_start_thread;
	}
	return (life_time);
}
