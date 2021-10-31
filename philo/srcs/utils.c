/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 23:15:23 by sglossu           #+#    #+#             */
/*   Updated: 2021/10/31 02:53:29 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
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

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned int	i;

	i = 0;
	while ((unsigned char)str1[i] != '\0' && (unsigned char)str2[i] != '\0')
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if ((unsigned char)str1[i] != '\0' || (unsigned char)str2[i] != '\0')
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}

void	message(char *str, t_thread philo)
{
	long	time;

	pthread_mutex_lock(&philo.mutex[philo.nbs_phils]);
	time = time_now() - philo.time_start_program;
	ft_putnbr_long(time);
	ft_putchar(' ');
	ft_putnbr_long(philo.philo_id);
	ft_putchar(' ');
	ft_putstr(str);
	if (ft_strcmp(str, "died"))
		pthread_mutex_unlock(&philo.mutex[philo.nbs_phils]);
}
