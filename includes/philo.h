/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:13:06 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/09 21:30:03 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <pthread.h>

typedef	struct s_data
{
	int	nbs_phils;
	int	t_die;
	int t_eat;
	int t_sleep;
	int	nbs_eating;
	int	c; // delete
}				t_data;

void	errors(char *str);
void	valid_arguments(int argc, char **argv, t_data *ph);
void	init_struct_five(t_data *ph, char **argv);
void	init_struct_six(t_data *ph, char **argv);
int		ft_atoi(const char *str);
void	thread(t_data *ph);

#endif 