/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:37 by maeskhai          #+#    #+#             */
/*   Updated: 2025/06/02 12:35:57 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_pthread_create(t_table *lst)
{
	int	i;

	pthread_create(&lst->check_die, NULL, ft_check_die, lst);
	i = 0;
	while (i < lst->nb_philos)
	{
		pthread_create(&lst->philos[i].thread, 
			NULL, philo_routine, &lst->philos[i]);
		i++;
	}
}

void	ft_pthread_join(t_table *lst)
{
	int	i;

	pthread_join(lst->check_die, NULL);
	i = 0;
	while (i < lst->nb_philos)
	{
		pthread_join(lst->philos[i].thread, NULL);
		i++;
	}
}

void	ft_creat_philos(t_table *lst)
{
	int	i;

	i = 0;
	lst->philos = malloc(sizeof(t_philo) * lst->nb_philos);
	if (!lst->philos)
	{
		ft_print_error("Error\n");
		return ;
	}
	while (i < lst->nb_philos)
	{
		lst->philos[i].index = i + 1;
		lst->philos[i].meal_count = 0;
		lst->philos[i].last_meal = get_time_ms();
		lst->philos[i].left_fork = &lst->forks[i];
		lst->philos[i].right_fork = &lst->forks[(i + 1) % lst->nb_philos];
		lst->philos[i].table = lst;
		i++;
	}
	lst->is_dead = 0;
	if (lst->nb_of_meals == 0)
		return ;
	ft_pthread_create(lst);
	ft_pthread_join(lst);
}

void	l(void)
{
	system("leaks -q philo");
}

int	main(int ac, char **av)
{
	t_table	lst;

	atexit(l);
	if (ac == 5 || ac == 6)
	{
		if (ft_check_nbrs(ac, av, &lst) == -1)
		{
			ft_print_error("Error\n");
			return (1);
		}
		ft_forks_to_philos(&lst);
		lst.start_time = get_time_ms();
		ft_creat_philos(&lst);
		ft_cleanup(&lst);
	}
	else
	{
		ft_print_error("Error\n");
		return (1);
	}
}
