/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:24:42 by maeskhai          #+#    #+#             */
/*   Updated: 2025/06/08 18:34:20 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		ft_print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		ft_print_status(philo, "has taken a fork");
	}
}

void	ft_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

int	is_dead_check(t_table *table)
{
	int	ret;

	pthread_mutex_lock(&table->death_mutex);
	ret = table->is_dead;
	pthread_mutex_unlock(&table->death_mutex);
	return (ret);
}

int	is_dead(t_philo *philo)
{
	return (is_dead_check(philo->table));
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->index % 2 == 0)
		ft_usleep(philo->table->time_to_eat / 2, philo->table);
	while (is_dead(philo) == 0)
	{
		if (is_dead(philo))
			break ;
		ft_print_status(philo, "is thinking");
		if (is_dead(philo))
			break ;
		philo_eat(philo);
		if (is_dead(philo))
			break ;
		ft_print_status(philo, "is sleeping");
		if (is_dead(philo))
			break ;
		ft_usleep(philo->table->time_to_sleep, philo->table);
	}
	return (NULL);
}
