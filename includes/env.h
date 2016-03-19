/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:19:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 15:07:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "philo_list.h"
# include "window.h"

typedef struct		s_env
{
	t_philo_list	*philos;
	t_window		*window;
}					t_env;

#endif
