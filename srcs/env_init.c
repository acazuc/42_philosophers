/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:30:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 11:46:32 by acazuc           ###   ########.fr       */
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
}

void		env_init(t_env *env)
{
	t_philo		*prev;
	t_philo		*curr;
	int			i;

	prev = NULL;
	i = 0;
	while (i < 7)
	{
		curr = philo_create();
		if (prev)
			curr->left = prev->right;
		curr->right = PTHREAD_MUTEX_INITIALIZER;
		if (pthread_mutex_init(curr->right, NULL))
			ERROR("Failed to init mutex");
		push_philo(env, curr);
		prev = curr;
		i++;
	}
	set_last_link(env);
}
