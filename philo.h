/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:51:56 by maeskhai          #+#    #+#             */
/*   Updated: 2025/06/08 15:23:09 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				index;
	int				meal_count;
	long long		last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
	pthread_t		thread;
}	t_philo;

typedef struct s_table
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_meals;
	int				is_dead;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_t		check_die;
	t_philo			*philos;
}	t_table;

void	ft_print_error(char *s);
int		ft_atoi(char *s);
int		ft_check_nbrs(int ac, char **av, t_table *table);
void	ft_forks_to_philos(t_table *table);
void	ft_creat_philos(t_table *table);
long	get_time_ms(void);
void	*philo_routine(void *arg);
void	ft_print_status(t_philo *philo, char *msg);
void	*ft_check_die(void	*arg);
void	ft_usleep(long microseconds, t_table *table);
void	ft_cleanup(t_table *table);
int		is_dead_check(t_table *table);

#endif