/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:03:01 by maeskhai          #+#    #+#             */
/*   Updated: 2025/05/28 19:37:51 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_last_time(t_table *lst)
{
	int			i;
	long long	time;

	i = 0;
	while (i < lst->nb_philos)
	{
		time = get_time_ms();
		if (time - lst->philos[i].last_meal >= lst->time_to_die)
		{
			ft_print_status(&lst->philos[i], "is died");
			pthread_mutex_lock(&lst->death_mutex);
			lst->is_dead = 1;
			pthread_mutex_unlock(&lst->death_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_max_eat(t_table *lst)
{
	int	i;
	int	full;

	i = 0;
	full = 0;
	while (i < lst->nb_philos)
	{
		pthread_mutex_lock(&lst->eat_mutex);
		if (lst->philos[i].meal_count >= lst->nb_of_meals)
			full++;
		pthread_mutex_unlock(&lst->eat_mutex);
		i++;
	}
	if (full == lst->nb_philos)
	{
		pthread_mutex_lock(&lst->death_mutex);
		lst->is_dead = 1;
		pthread_mutex_unlock(&lst->death_mutex);
		return (1);
	}
	return (0);
}

void	*ft_check_die(void	*arg)
{
	t_table	*lst;

	lst = (t_table *)arg;
	while (!lst->is_dead)
	{
		if (ft_last_time(lst) || ft_max_eat(lst))
			break ;
	}
	return (NULL);
}
