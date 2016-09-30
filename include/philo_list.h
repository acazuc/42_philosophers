/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:23:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 11:24:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_LIST_H
# define PHILO_LIST_H

# include "philo.h"

typedef struct s_philo_list	t_philo_list;

struct				s_philo_list
{
	t_philo			*philo;
	t_philo_list	*next;
};

#endif
