/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:03:01 by maeskhai          #+#    #+#             */
/*   Updated: 2025/06/05 17:27:34 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_last_time(t_table *table)
{
	int			i;
	long long	time;

	i = 0;
	while (i < table->nb_philos)
	{
		time = get_time_ms();
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
		pthread_mutex_lock(&table->eat_mutex);
		if (table->philos[i].meal_count >= table->nb_of_meals)
			full++;
		pthread_mutex_unlock(&table->eat_mutex);
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
	while (!table->is_dead)
	{
		if (ft_last_time(table) || ft_max_eat(table))
			break ;
	}
	return (NULL);
}
