/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:28:30 by sglossu           #+#    #+#             */
/*   Updated: 2021/10/08 23:14:46 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	init_dop(t_data *all, int count)
{
	count = 0;
	while (count < all->nbs_phils)
	{
		all->philo[count].philo_id = count + 1;
		all->philo[count].left_fork = count + 1;
		if (all->philo[count].left_fork == all->nbs_phils)
			all->philo[count].left_fork = 0;
		all->philo[count].right_fork = count;
		all->philo[count].t_die = all->t_die;
		all->philo[count].t_eat = all->t_eat;
		all->philo[count].t_sleep = all->t_sleep;
		all->philo[count].nbs_phils = all->nbs_phils;
		all->philo[count].time_start_eat = 0;
		all->philo[count].nbs_eating = all->nbs_eating;
		all->philo[count].count_eating = 0;
		all->philo[count].gorged = false;
		all->philo[count].ph_die = false;
		all->philo[count].time_start_program = all->time_start_program;
		all->philo[count].time_start_eat = 0;
		all->philo[count].forks = all->forks;
		all->philo[count].print = all->print;
//		printf("count %d, pointer forks %p\n", count, all->forks);
//		printf("count %d, pointer print %p\n", count, all->print);
		count++;
	}
}

static void init_forks(t_data *all)
{
	sem_unlink("forks");
	sem_unlink("print");
	all->forks = sem_open("forks", O_CREAT, S_IRWXU, all->nbs_phils);
	if (!all->forks)
		exit (-1);
	all->print = sem_open("forks", O_CREAT, S_IRWXU, 1);
	if (!all->print)
		exit (-1);
}

int	init_struct(t_data *all, char **argv, int  argc)
{
	all->nbs_phils = ft_atoi(argv[1]);
	all->t_die = ft_atoi(argv[2]);
	all->t_eat = ft_atoi(argv[3]);
	all->t_sleep = ft_atoi(argv[4]);
	all->time_start_program = 0;
	all->count_gorged_philo = 0;
	if (argc == 5)
		all->nbs_eating = 0;
	else
		all->nbs_eating = ft_atoi(argv[5]);
	all->philo = (t_thread *)malloc(sizeof(t_thread) * (all->nbs_phils + 1));
	if (all->philo == NULL)
	{
		ft_putstr("No memory allocated");
		return (0);
	}
	init_forks(all);
	init_dop(all, -1);
	return (1);
}
