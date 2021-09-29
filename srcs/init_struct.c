 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:28:30 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/09 19:46:52 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct_five(t_data *all, char **argv)
{
	int count;

	count = 0;
	all->nbs_phils = ft_atoi(argv[1]);
	all->t_die = ft_atoi(argv[2]);
	all->t_eat = ft_atoi(argv[3]);
	all->t_sleep = ft_atoi(argv[4]);
	all->nbs_eating = 0;
	all->philo = (t_thread *)malloc(sizeof(t_thread) * all->nbs_phils);
	if (all->philo == NULL)
		errors("No memory allocated");
	all->table = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (all->nbs_phils + 1));
	if (all->table == NULL)
		errors("No memory allocated");
	while (count < all->nbs_phils + 1)
	{
		pthread_mutex_init(&all->table[count], NULL);
		count++;
	}
	count = 0;
	while (count < all->nbs_phils)
	{
		all->philo[count].mutex = all->table;
		all->philo[count].philo_id = count;
		all->philo[count].left_fork = count + 1;
		if (all->philo[count].left_fork == all->nbs_phils)
			all->philo[count].left_fork = 0;
		all->philo[count].right_fork = count;
		all->philo[count].t_die = all->t_die;
		all->philo[count].t_eat = all->t_eat;
		all->philo[count].t_sleep = all->t_sleep;
//		printf("init: philo->philo_id %d\n", all->philo[count].philo_id);
		count++;
	}
}

void	init_struct_six(t_data *all, char **argv)
{
	int count;

	count = 0;
	all->nbs_phils = ft_atoi(argv[1]);
	all->t_die = ft_atoi(argv[2]);
	all->t_eat = ft_atoi(argv[3]);
	all->t_sleep = ft_atoi(argv[4]);
	all->nbs_eating = ft_atoi(argv[5]);
	all->philo = (t_thread *)malloc(sizeof(t_thread) * all->nbs_phils);
//	if (all->philo == NULL)
//		errors("No memory allocated");
//	all->philo->table.mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * all->nbs_phils);
//	if (all->philo->table.mutex == NULL)
//		errors("No memory allocated");
//	while (count < all->nbs_phils)
//	{
//		pthread_mutex_init(&all->philo->table.mutex[count], NULL);
//		count++;
//	}
//	count = 0;
//	while (count < all->nbs_phils)
//	{
//		all->philo[count].philo_id = count;
//		all->philo[count].left_fork = count + 1;
//		if (all->philo[count].left_fork == all->nbs_phils)
//			all->philo[count].left_fork = 0;
////		printf("init left fork: %d\n", all->philo[count].left_fork);
//		all->philo[count].right_fork = count;
//		all->philo[count].t_die = all->t_die;
//		all->philo[count].t_eat = all->t_eat;
//		all->philo[count].t_sleep = all->t_sleep;
//		count++;
//	}
}