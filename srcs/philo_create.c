/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:32:19 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 17:42:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*philo_create(void)
{
	t_philo	*philo;

	if (!(philo = malloc(sizeof(*philo))))
		ERROR("Failed to malloc new philosopher");
	philo->left = NULL;
	philo->right = NULL;
	philo->life = MAX_LIFE;
	philo->release_request = 0;
	philo->eat_count = 0;
	philo->rest_count = 0;
	philo->think_count = 0;
	return (philo);
}
