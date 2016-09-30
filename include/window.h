/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 15:07:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/19 15:09:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct			s_window
{
	void				*mlx_window;
	void				*mlx;
	void				*img;
	char				*data;
	int					width;
	int					height;
	int					bpp;
	int					endian;
}						t_window;

#endif
