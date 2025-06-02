/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:06 by maeskhai          #+#    #+#             */
/*   Updated: 2025/05/28 19:40:58 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_nbrs(int ac, char **av, t_table *lst)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[1]) != -1)
			lst->nb_philos = (ft_atoi(av[1]));
		if (ft_atoi(av[2]) != -1)
			lst->time_to_die = (ft_atoi(av[2]));
		if (ft_atoi(av[3]) != -1)
			lst->time_to_eat = (ft_atoi(av[3]));
		if (ft_atoi(av[4]) != -1)
			lst->time_to_sleep = (ft_atoi(av[4]));
		if (i == 5)
		{
			if (ft_atoi(av[5]) != -1)
				lst->nb_of_meals = (ft_atoi(av[5]));
		}
		if (ft_atoi(av[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}
