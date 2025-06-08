/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:58:26 by maeskhai          #+#    #+#             */
/*   Updated: 2025/06/08 17:02:45 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	if (philo->table->nb_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		if (!is_dead(philo))
			ft_print_status(philo, "has taken a fork");
		ft_usleep(philo->table->time_to_die, philo->table);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	take_forks(philo);
	if (is_dead(philo))
	{
		ft_unlock_forks(philo);
		return ;
	}
	ft_print_status(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time_ms();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_usleep(philo->table->time_to_eat, philo->table);
	ft_unlock_forks(philo);
}
