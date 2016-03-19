/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_health.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:07:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 16:10:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void		draw_health_bg(t_env *env, int x, int y)
{
	int		tx;
	int		ty;

	ty = -5;
	while (ty <= -1)
	{
		tx = -35;
		while (tx <= 35)
		{
			pixel_put(env, x + tx, y + ty, 0);
			tx++;
		}
		ty++;
	}
}

static void		draw_health_dead(t_env *env, int x, int y)
{
	int		tx;
	int		ty;

	ty = -5;
	while (++ty <=-2)
	{
		tx = -35;
		while (++tx <= 34)
			pixel_put(env, x + tx, y + ty, 0xFF0000);
	}
}

void			draw_health(t_env *env, t_philo *philo, int x, int y)
{
	int		tx;
	int		ty;

	draw_health_bg(env, x, y);
	if (!philo->life)
		draw_health_dead(env, x, y);
	else
	{
		ty = -5;
		while (++ty <= -2)
		{
			tx = -35;
			while (++tx <= -34 + (68 * ((float)philo->life / (float)MAX_LIFE)))
				pixel_put(env, x + tx, y + ty, 0x66FF66);
		}
	}
}
