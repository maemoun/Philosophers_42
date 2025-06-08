/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:57:18 by maeskhai          #+#    #+#             */
/*   Updated: 2025/06/08 16:57:32 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_status(t_philo *philo, char *msg)
{
	long long	timestamp;

	pthread_mutex_lock(&philo->table->print_mutex);
	pthread_mutex_lock(&philo->table->death_mutex);
	if (!philo->table->is_dead)
	{
		timestamp = get_time_ms() - philo->table->start_time;
		printf("%lld %d %s\n", timestamp, philo->index, msg);
	}
	pthread_mutex_unlock(&philo->table->death_mutex);
	pthread_mutex_unlock(&philo->table->print_mutex);
}
