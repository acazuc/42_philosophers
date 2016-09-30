/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 14:52:29 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 16:57:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void		draw_status(t_env *env, t_philo *philo, int x, int y)
{
	y++;
	if (philo->eat_count)
	{
		x -= 34;
		pixel_put(env, x - 1, y - 0, 0);
		pixel_put(env, x - 1, y + 1, 0);
		pixel_put(env, x - 1, y + 2, 0);
		pixel_put(env, x - 1, y + 3, 0);
		pixel_put(env, x - 1, y + 4, 0);
		pixel_put(env, x + 0, y - 0, 0);
		pixel_put(env, x + 1, y + 0, 0);
		pixel_put(env, x + 0, y + 2, 0);
		pixel_put(env, x + 0, y + 4, 0);
		pixel_put(env, x + 1, y + 4, 0);
	}
	else if (philo->rest_count)
	{
		x -= 30;
		pixel_put(env, x - 1, y + 0, 0);
		pixel_put(env, x - 1, y + 1, 0);
		pixel_put(env, x - 1, y + 2, 0);
		pixel_put(env, x - 1, y + 3, 0);
		pixel_put(env, x - 1, y + 4, 0);
		pixel_put(env, x + 0, y + 0, 0);
		pixel_put(env, x + 1, y + 1, 0);
		pixel_put(env, x + 0, y + 2, 0);
		pixel_put(env, x + 1, y + 3, 0);
		pixel_put(env, x + 1, y + 4, 0);
	}
	else if (philo->think_count)
	{
		x -= 26;
		pixel_put(env, x - 1, y + 0, 0);
		pixel_put(env, x + 0, y + 0, 0);
		pixel_put(env, x + 1, y + 0, 0);
		pixel_put(env, x + 0, y + 1, 0);
		pixel_put(env, x + 0, y + 2, 0);
		pixel_put(env, x + 0, y + 3, 0);
		pixel_put(env, x + 0, y + 4, 0);
	}
}

static void		draw_philo(t_env *env, t_philo *philo, int x, int y)
{
	draw_health(env, philo, x, y);
	draw_status(env, philo, x, y);
}

static void		reset(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < env->window->width)
	{
		y = 0;
		while (y < env->window->height)
		{
			pixel_put(env, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}

int		display(void *data)
{
	t_philo_list	*lst;
	t_env			*env;
	int				i;
	int				x;
	int				y;

	env = (t_env*)data;
	reset(env);
	lst = env->philos;
	i = 0;
	while (i < 7)
	{
		if (lst->philo->life == 0)
			pthread_detach(lst->philo->thread);
		x = env->window->width / 2. + cos(i / 7. * M_PI * 2.)
			* (env->window->width / 4.);
		y = env->window->height / 2. + sin(i / 7. * M_PI * 2.)
			* (env->window->height / 4.);
		draw_philo(env, lst->philo, x, y);
		lst = lst->next;
		i++;
	}
	mlx_put_image_to_window(env->window->mlx, env->window->mlx_window, env->window->img, 0, 0);
	return (0);
}
