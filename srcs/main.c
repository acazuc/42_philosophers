/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:17:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 15:17:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		main(void)
{
	t_env	env;

	env_init(&env);
	window_init(&env);
	start_threads(&env);
	mlx_loop_hook(env.window->mlx, display, &env);
	mlx_loop(env.window->mlx);
}
