/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:08:52 by maeskhai          #+#    #+#             */
/*   Updated: 2025/05/28 18:08:37 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long microseconds, t_table *lst)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start <= microseconds)
	{
		if (lst->is_dead == 1)
			break ;
		usleep(400);
	}
	return ;
}
