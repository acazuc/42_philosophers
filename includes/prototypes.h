/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:03:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 13:49:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "philo.h"
# include "env.h"

void	error_quit(char *msg, char *file, int line);
void	env_init(t_env *env);
void	start_threads(t_env *env);
t_philo	*philo_create(void);
void	*tick(void *data);
void	tick_eat(t_philo *philo);
void	tick_think(t_philo *philo);

#endif
