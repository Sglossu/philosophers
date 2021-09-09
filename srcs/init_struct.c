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

void	init_struct_five(t_data *ph, char **argv)
{
	ph->nbs_phils = ft_atoi(argv[1]);
	ph->t_die = ft_atoi(argv[2]);
	ph->t_eat = ft_atoi(argv[3]);
	ph->t_sleep = ft_atoi(argv[4]);
	ph->nbs_eating = 0;
}

void	init_struct_six(t_data *ph, char **argv)
{
	ph->nbs_phils = ft_atoi(argv[1]);
	ph->t_die = ft_atoi(argv[2]);
	ph->t_eat = ft_atoi(argv[3]);
	ph->t_sleep = ft_atoi(argv[4]);
	ph->nbs_eating = ft_atoi(argv[5]);
}