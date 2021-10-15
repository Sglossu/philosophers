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

int	ft_free(t_data *all)
{
	int	count;

	count = 0;
	while (count < all->nbs_phils + 1)
	{
		if (pthread_mutex_destroy(all->table + count))
			return (-1);
		count++;
	}
	count = 0;
	while (count < all->nbs_phils + 1)
	{
		if (pthread_detach(all->philo[count].t))
			return (-1);
		count++;
	}
	free(all->philo);
	free(all->table);
	free(all);
	return (1);
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
		return (-1);
	}
	if (!thread(all))
	{
		ft_free(all);
		return (-1);
	}
	ft_free(all);
	return (1);
}
