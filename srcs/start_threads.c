/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:06:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 13:59:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_threads(t_env *env)
{
	t_philo_list	*lst;

	lst = env->philos;
	while (lst)
	{
		if (pthread_create(&lst->philo->thread, NULL, tick, lst->philo))
			ERROR("Failed to start thread");
		lst = lst->next;
	}
	lst = env->philos;
	while (lst)
	{
		pthread_join(lst->philo->thread, NULL);
		ft_putstr("joined thread\n");
		lst = lst->next;
	}
}
