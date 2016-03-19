/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:03:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 16:09:09 by acazuc           ###   ########.fr       */
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
int		tick_eat(t_philo *philo);
int		tick_think(t_philo *philo);
void	window_init(t_env *env);
void	pixel_put(t_env *env, int x, int y, unsigned int color);
int		display(void *data);
void	draw_health(t_env *env, t_philo *philo, int x, int y);

#endif
