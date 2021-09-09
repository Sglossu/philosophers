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

void	*ft_func()
{
	print()
	return (0);
}

void	thread(t_data *ph)
{
	(void)ph;
	pthread_t	t1;
	pthread_t	t2;
	char		*str1 = "1_1_1_\n";
	char		*str2 = "2_2_2_\n";
	
	pthread_create(&t1, NULL, ft_func, (void *)str1);
	pthread_create(&t2, NULL, ft_func, (void *)str2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
}