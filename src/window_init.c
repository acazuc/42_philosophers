/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 15:05:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 15:18:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	window_init(t_env *env)
{
	int		loul;

	if (!(env->window = malloc(sizeof(*env->window))))
		ERROR("Failed to malloc window struct");
	env->window->bpp = 8 * 3;
	env->window->endian = 1;
	env->window->width = 1000;
	env->window->height = 1000;
	loul = env->window->width * env->window->bpp / 8;
	if (!(env->window->mlx = mlx_init()))
		ERROR("Failed to init mlx context");
	if (!(env->window->mlx_window = mlx_new_window(env->window->mlx
					, env->window->width
					, env->window->height, "acazuc's philosophers")))
		ERROR("Failed to create window");
	if (!(env->window->img = mlx_new_image(env->window->mlx
					, env->window->width, env->window->height)))
		ERROR("Failed to create image");
	if (!(env->window->data = mlx_get_data_addr(env->window->img
					, &(env->window->bpp), &loul
					, &(env->window->endian))))
		ERROR("Failed to get image data");
}
