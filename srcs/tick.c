/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:52:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 18:01:06 by acazuc           ###   ########.fr       */
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

static long		current_us()
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void			*tick(void *arg)
{
	t_philo	*philo;
	long	tmp;

	philo = (t_philo*)arg;
	while (philo->life > 0)
	{
		tmp = current_us();
		if (philo->rest_count)
		{
			philo->life--;
			philo->rest_count--;
		}
		else if (((philo->life - EAT_T < MAX_LIFE || philo->eat_count)
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
		usleep(100000);
	}
	return (unlock(arg));
}
