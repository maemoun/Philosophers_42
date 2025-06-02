/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:11:55 by maeskhai          #+#    #+#             */
/*   Updated: 2025/06/02 13:19:51 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_cleanup(t_table *lst)
{
	if (lst->philos)
		free(lst->philos);
	if (lst->forks)
		free(lst->forks);
}
