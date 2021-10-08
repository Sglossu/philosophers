/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 23:15:23 by sglossu           #+#    #+#             */
/*   Updated: 2021/10/08 23:15:25 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long time_now(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		errors("error of time\n");
	return ((long)time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	my_usleep(long time)
{
	long	start;

	start = time_now();
	while (time > time_now() - start)
		usleep(40);
	return ;
}
