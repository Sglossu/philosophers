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
	{
		ft_putstr("No memory allocated");
		return (-1);
	}
	all->nbs_phils = 0;
	if(!valid_arguments(argc, argv, all))
	{
//		free;
		return (-1);
	}
	if (!thread(all))
	{
//		free;
		return (-1);
	}
//	free;
	return (1);
}
