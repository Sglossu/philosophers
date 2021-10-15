/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:17:50 by sglossu           #+#    #+#             */
/*   Updated: 2021/10/08 23:15:58 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	valid_if_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				ft_putstr("Invalid arguments, try to used only numbers!");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static	int	valid_incorrect_arguments(t_data *all)
{
	if (all->nbs_phils <= 0 || all->t_die <= 0 || \
	all->t_eat <= 0 || all->t_sleep <= 0)
	{
		ft_putstr("Incorrect arguments");
		return (0);
	}
	return (1);
}

static	int	valid_nbs_eating(t_data *all, int argc)
{
	if (all->nbs_eating <= 0 && argc == 6)
	{
		ft_putstr("Incorrect arguments");
		return (0);
	}
	return (1);
}

int	valid_arguments(int argc, char **argv, t_data *all)
{
	if (argc == 5 || argc == 6)
	{
		if (!valid_if_digit(argv))
			return (0);
		if (!init_struct(all, argv, argc))
			return (0);
		if (!valid_incorrect_arguments(all))
			return (0);
		if (!valid_nbs_eating(all, argc))
			return (0);
	}
	else
	{
		ft_putstr("Wrong number arguments!");
		return (0);
	}
	return (1);
}
