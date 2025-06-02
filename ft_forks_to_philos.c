/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:14:44 by maeskhai          #+#    #+#             */
/*   Updated: 2025/05/28 19:41:23 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_forks_to_philos(t_table *lst)
{
	int	i;

	i = 0;
	pthread_mutex_init(&lst->death_mutex, NULL);
	pthread_mutex_init(&lst->print_mutex, NULL);
	pthread_mutex_init(&lst->eat_mutex, NULL);
	lst->forks = malloc(sizeof(pthread_mutex_t) * lst->nb_philos);
	if (!lst->forks)
	{
		ft_print_error("Error\n");
		free(lst->philos);
		return ;
	}
	while (i < lst->nb_philos)
	{
		if (pthread_mutex_init(&lst->forks[i], NULL) != 0)
		{
			ft_print_error("Error\n");
			return ;
		}
		i++;
	}
}
