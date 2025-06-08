/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:03:01 by maeskhai          #+#    #+#             */
/*   Updated: 2025/06/08 15:45:11 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_last_time(t_table *table)
{
	int			i;
	long long	time;
	long long	last_meal;

	i = 0;
	while (i < table->nb_philos)
	{
		time = get_time_ms();

		pthread_mutex_lock(&table->eat_mutex);
		last_meal = table->philos[i].last_meal;
		pthread_mutex_unlock(&table->eat_mutex);
		if (time - table->philos[i].last_meal >= table->time_to_die)
		{
			ft_print_status(&table->philos[i], "is died");
			pthread_mutex_lock(&table->death_mutex);
			table->is_dead = 1;
			pthread_mutex_unlock(&table->death_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_max_eat(t_table *table)
{
	int	i;
	int	full;

	i = 0;
	full = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_lock(&table->philos[i].meal_mutex);
		if (table->philos[i].meal_count >= table->nb_of_meals)
			full++;
		pthread_mutex_unlock(&table->philos[i].meal_mutex);
		i++;
	}
	if (full == table->nb_philos)
	{
		pthread_mutex_lock(&table->death_mutex);
		table->is_dead = 1;
		pthread_mutex_unlock(&table->death_mutex);
		return (1);
	}
	return (0);
}

void	*ft_check_die(void	*arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (!is_dead_check(table))
	{
		if (ft_last_time(table))
			break ;
		if (table->nb_of_meals > 0 && ft_max_eat(table))
			break;
		usleep(1000);
	}
	return (NULL);
}
