/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:52:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 13:58:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void		*unlock(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->left) != EPERM)
		ERROR("Failed to unlock mutex");
	if (pthread_mutex_unlock(philo->right) != EPERM)
		ERROR("Faield to unlock mutex");
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
			philo->rest_count--;
		else if ((philo->life < MAX_LIFE || philo->eat_count)
				&& !philo->rest_count && !philo->think_count)
			tick_eat(philo);
		else if (!philo->eat_count && !philo->rest_count)
			tick_think(philo);
		usleep(1000000);
	}
	return (arg);
}
