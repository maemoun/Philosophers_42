/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:06 by maeskhai          #+#    #+#             */
/*   Updated: 2025/06/05 20:31:00 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check(t_table *table)
{
	if (table->nb_philos == 0 || table->time_to_die == 0 
		|| table->time_to_eat == 0 || table->time_to_sleep == 0)
		return (-1);
	return (1);
}

int	ft_check_nbrs(int ac, char **av, t_table *table)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[1]) != -1)
			table->nb_philos = (ft_atoi(av[1]));
		if (ft_atoi(av[2]) != -1)
			table->time_to_die = (ft_atoi(av[2]));
		if (ft_atoi(av[3]) != -1)
			table->time_to_eat = (ft_atoi(av[3]));
		if (ft_atoi(av[4]) != -1)
			table->time_to_sleep = (ft_atoi(av[4]));
		if (i == 5)
		{
			if (ft_atoi(av[5]) != -1)
				table->nb_of_meals = (ft_atoi(av[5]));
		}
		if (ft_check(table) == -1)
			return (-1);
		if (ft_atoi(av[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}
