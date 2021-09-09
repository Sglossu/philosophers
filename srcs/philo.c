/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:14:11 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/09 20:22:52 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	errors(char *str)
{
	printf("%s\n", str);
	exit (-1);
}

int main(int argc, char **argv)
{
	t_data	ph;

	ph.c = 0; // delete
	valid_arguments(argc, argv, &ph);
	// printf("ph->nbs_phils (number_of_philosophers) ---->    %d\n", ph.nbs_phils);
	// printf("ph->t_die (time_to_die) ---->    %d\n", ph.t_die);
	// printf("ph->t_eat (time_to_eat) ---->    %d\n", ph.t_eat);
	// printf("ph->t_sleep (time_to_sleep) ---->    %d\n", ph.t_sleep);
	// printf("ph->nbs_eating (number_of_times_philo_must_eat) ---->    %d\n", ph.nbs_eating);
	thread(&ph);
	return (1);
}