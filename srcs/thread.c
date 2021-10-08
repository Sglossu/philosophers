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


_Noreturn void	*death_func(void *philo_m)
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
//
//		printf("%d start eat in %ld, start thread in %ld\n", (*philo)[count].philo_id, (*philo)[0].time_start_eat, (*philo)[count].time_start_thread);
//		printf("%d философ живёт ------------------> %ld\n", (*philo)[count].philo_id, life_time);
//
//
		if ((*philo)[count].gorged)
		{
			(*philo)[count].gorged = false;
			count_gorged_philo++;
//			printf("count_gorged_philo: %d\n", count_gorged_philo);
//			printf("поесть надо %d раза\n", (*philo)[count].nbs_eating);
		}
		if (count_gorged_philo == (*philo)[count].nbs_phils && (*philo)[count].nbs_eating != 0)
		{
			printf("наелись\n");
			exit (1);
		}
		if (life_time > (long)(*philo)[count].t_die)
		{
			printf("%ld %d died %\n", life_time, (*philo)[count].philo_id);
			exit (-1);
		}
		count++;
		if (count == (*philo)[0].nbs_phils)
			count = 0;
	}
}

void	*ft_func(void *philo_m)
{
	t_thread	*philo;
	long		time;

	time = time_now();
	philo = philo_m;
//	printf("%d time start tread: %ld\n", philo->philo_id, philo->time_start_thread);

	while(1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);

	}
}

void	thread(t_data *all)
{
	int count = 0;



	while (count < all->nbs_phils) {
		all->philo[count].time_start_thread = time_now();
//		printf("%d start in %ld\n", all->philo[count].philo_id, all->philo[count].time_start_thread - all->time_start_program);
		pthread_create(&all->philo[count].t, NULL, ft_func,  &all->philo[count]);
		count++;
	}

	pthread_create(&all->philo[count].t, NULL, death_func,  &all->philo); // поток для контроля смерти
	count = 0;
	while (count < all->nbs_phils) {
		pthread_join(all->philo[count].t, NULL);
		count++;
	}
//	death_func(all);
//     usleep(1000);
}
