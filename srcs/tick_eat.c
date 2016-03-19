/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick_eat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:22:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 13:50:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int		lock(t_philo *philo)
{
	int		err;

	if ((err = pthread_mutex_trylock(philo->left)) == EBUSY)
		return (0);
	else if (err)
		ERROR("mutex_trylock hard failed");
	if ((err = pthread_mutex_trylock(philo->right)) == EBUSY)
	{
		if (pthread_mutex_unlock(philo->left))
			ERROR("mutex_unlock hard failed");
		return (0);
	}
	else if (err)
		ERROR("mutex_trylock hard failed");
	return (1);
}

void			tick_eat(t_philo *philo)
{
	if (!philo->eat_count)
	{
		if (!lock(philo))
			return ;
		philo->eat_count = EAT_T;
	}
	else
		philo->eat_count--;
	if (philo->eat_count == 0)
	{
		if (pthread_mutex_unlock(philo->left))
			ERROR("mutex_unlock hard failed");
		if (pthread_mutex_unlock(philo->right))
			ERROR("mutex_unlock hard failed");
		philo->life = MAX_LIFE;
		philo->rest_count = REST_T;
	}
}
