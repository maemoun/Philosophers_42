/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:08:52 by maeskhai          #+#    #+#             */
/*   Updated: 2025/06/08 16:59:50 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long microseconds, t_table *table)
{
	long	start;
	int		dead;

	start = get_time_ms();
	while (get_time_ms() - start <= microseconds)
	{
		pthread_mutex_lock(&table->death_mutex);
		dead = table->is_dead;
		pthread_mutex_unlock(&table->death_mutex);
		if (dead == 1)
			break ;
		usleep(400);
	}
	return ;
}
