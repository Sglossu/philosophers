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


//void	ft_putnbr_long(long n)
//{
//	long	x;
//
//	x = 0;
//	if (n < 0)
//	{
//		write(1, "-", 1);
//		n = -n;
//	}
//	if (n >= 10)
//	{
//		ft_putnbr_long(n / 10);
//		x = n % 10 + '0';
//		write(1, &x, 1);
//	}
//	else
//	{
//		x = n + '0';
//		write(1, &x, 1);
//	}
//}
//
//void	ft_putnbr(int n)
//{
//	int	x;
//
//	x = 0;
//	if (n < 0)
//	{
//		write(1, "-", 1);
//		n = -n;
//	}
//	if (n >= 10)
//	{
//		ft_putnbr(n / 10);
//		x = n % 10 + '0';
//		write(1, &x, 1);
//	}
//	else
//	{
//		x = n + '0';
//		write(1, &x, 1);
//	}
//}
//
void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

//void	message(long time, int philo_id, char *str)
//{
////	ft_putnbr_long(time);
////	write(1, " ", 1);
////	ft_putnbr(philo_id);
////	write(1, " ", 1);
//	ft_putstr(str);
//}