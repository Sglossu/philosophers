/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:14:11 by sglossu           #+#    #+#             */
/*   Updated: 2021/10/08 23:15:42 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data *all)
{
	int	count;

	count = 0;
	while (count < all->nbs_phils)
	{
		if (pthread_detach(all->philo[count].t))
			exit (1);
		count++;
	}
	free(all->philo);
	free(all);
}

int	main(int argc, char **argv)
{
	t_data	*all;

	all = malloc(sizeof(t_data));
	if (all == NULL)
	{
		ft_putstr("No memory allocated");
		return (-1);
	}
	all->nbs_phils = 0;
	if (!valid_arguments(argc, argv, all))
	{
		ft_free(all);
	}
	thread(all);
	sem_close(all->forks);
	sem_close(all->print);
	ft_free(all);
	return (1);
}
