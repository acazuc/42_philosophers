/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick_think.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:31:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 13:51:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	lock(t_philo *philo)
{
	int		err;

	if ((err = pthread_mutex_trylock(philo->left)) == EBUSY)
	{
		if ((err = pthread_mutex_trylock(philo->right)) == EBUSY)
			return (0);
		else if (err)
			ERROR("mutex_trylock hard failed");
	}
	else if (err)
		ERROR("mutex_trylock hard failed");
	return (1);
}

void	tick_think(t_philo *philo)
{
	int		err;

	if (!philo->think_count)
	{
		if (!lock(philo))
			return ;
		philo->think_count = THINK_T;
	}
	else
		philo->think_count--;
	if (philo->think_count == 0)
	{
		if ((err = pthread_mutex_unlock(philo->left)) == EPERM)
		{
			if ((err = pthread_mutex_unlock(philo->right)) != EPERM)
				ERROR("mutex_unlock hard failed");
		}
		else if (err)
			ERROR("mutex_unlock hard failed");
	}
}
