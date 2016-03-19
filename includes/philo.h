/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:24:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 15:34:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct		s_philo
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_t		thread;
	int				life;
	int				eat_count;
	int				rest_count;
	int				think_count;
}					t_philo;

#endif
