/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:24:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 17:19:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_philo	t_philo;

struct		s_philo
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_t		thread;
	t_philo			*philo_left;
	t_philo			*philo_right;
	int				release_request;
	int				life;
	int				eat_count;
	int				rest_count;
	int				think_count;
};

#endif
