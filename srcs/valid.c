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

static	void	valid_if_digit(char **argv)
{
	int i;
	int j;

	i = 1; // потому что 0 - это имя программы
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				errors("Invalid arguments, try to used only numbers!");
			j++;
		}
		i++;
	}
}

void valid_arguments(int argc, char **argv, t_data *all)
{
	if (argc == 5 || argc == 6)
	{
		valid_if_digit(argv);
		init_struct(all, argv, argc);
	}
	else
		errors("Wrong number argunemts!");
}
