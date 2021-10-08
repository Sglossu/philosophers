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

void	errors(char *str)
{
	printf("%s\n", str);
	exit (-1);
}

int main(int argc, char **argv)
{
	t_data	*all;
	int		count = 0;

	all = malloc(sizeof(t_data));
	if (all == NULL)
		errors("No memory allocated");
	all->c = 0; // delete
	valid_arguments(argc, argv, all);
//	all->time_start_program = time_now();
//	while (count < all->nbs_phils) {
//		all->philo[count].time_start_program = all->time_start_program;
//		count++;
//	}
	thread(all);
	return (1);
}
