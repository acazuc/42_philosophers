/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:52:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 18:10:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/time.h>

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
	while (philo->life > 0)
	{
		if (philo->think_count)
			philo->think_count--;
		if (philo->rest_count)
		{
			philo->life--;
			philo->rest_count--;
		}
		else if (((philo->life - EAT_T < MAX_LIFE || philo->eat_count)
				|| (!philo->rest_count && !philo->think_count)) && tick_eat(philo))
		{
		}
		else
		{
			if (pthread_mutex_trylock(philo->left))
			{
				pthread_mutex_unlock(philo->left);
				philo->life--;
				philo->think_count = 1;
			}
			else if (pthread_mutex_trylock(philo->right))
			{
				pthread_mutex_unlock(philo->right);
				philo->life--;
				philo->think_count = 1;
			}
		}
		usleep(10000000);
	}
	return (unlock(arg));
}
