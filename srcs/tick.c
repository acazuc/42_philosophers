/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:52:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 16:05:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

static void		*unlock(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	return (philo);
}

void			*tick(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	while (1)
	{
		if (philo->life == 0)
			return (unlock(philo));
		if (philo->rest_count)
		{
			philo->life--;
			philo->rest_count--;
		}
		else if (((philo->life < MAX_LIFE || philo->eat_count)
				|| (!philo->rest_count && !philo->think_count)) && tick_eat(philo))
		{
		}
		/*else if (philo->think_count || (!philo->eat_count && !philo->rest_count))
		{
			tick_think(philo);
			philo->life--;
		}*/
		else
			philo->life--;
		usleep(10000);
	}
	return (arg);
}
