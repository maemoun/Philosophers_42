/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:08:52 by maeskhai          #+#    #+#             */
/*   Updated: 2025/06/05 17:27:13 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long microseconds, t_table *table)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start <= microseconds)
	{
		if (table->is_dead == 1)
			break ;
		usleep(400);
	}
	return ;
}
