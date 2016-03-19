/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:30:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 17:11:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	push_philo(t_env *env, t_philo *philo)
{
	t_philo_list	*new;
	t_philo_list	*lst;

	if (!(new = malloc(sizeof(*new))))
		ERROR("Failed to malloc new philo_list");
	new->philo = philo;
	new->next = NULL;
	if (!env->philos)
		env->philos = new;
	else
	{
		lst = env->philos;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}

static void	set_last_link(t_env *env)
{
	t_philo_list	*lst;
	t_philo			*last;

	lst = env->philos;
	while (lst->next)
		lst = lst->next;
	last = lst->philo;
	env->philos->philo->left = last->right;
	last->philo_right = env->philos->philo;
	env->philos->philo->philo_left = last;
}

void		env_init(t_env *env)
{
	t_philo		*prev;
	t_philo		*curr;
	int			i;

	env->philos = NULL;
	prev = NULL;
	i = 0;
	while (i < 7)
	{
		curr = philo_create();
		if (prev)
		{
			curr->left = prev->right;
			prev->philo_right = curr;
		}
		curr->philo_left = prev;
		if (!(curr->right = malloc(sizeof(*curr->right))))
			ERROR("Failed to malloc mutex");
		if (pthread_mutex_init(curr->right, NULL))
			ERROR("Failed to init mutex");
		push_philo(env, curr);
		prev = curr;
		i++;
	}
	set_last_link(env);
}
