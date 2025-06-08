/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:24:42 by maeskhai          #+#    #+#             */
/*   Updated: 2025/06/08 15:43:35 by maeskhai         ###   ########.fr       */
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

void	philo_eat(t_philo *philo)
{
	if (philo->table->nb_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print_status(philo, "has taken a fork");
		ft_usleep(philo->table->time_to_die, philo->table);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	take_forks(philo);
	ft_print_status(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time_ms();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_usleep(philo->table->time_to_eat, philo->table);
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
		ft_print_status(philo, "is thinking");
		philo_eat(philo);
		if (is_dead(philo))
			break ;
		ft_print_status(philo, "is sleeping");
		ft_usleep(philo->table->time_to_sleep, philo->table);
	}
	return (NULL);
}
