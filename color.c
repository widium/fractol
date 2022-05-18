/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:02:21 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/18 20:22:23 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pick_color(int i, t_env *env, int x, int y)
{
	if (i == env->model->iter_max)
		my_mlx_pixel_put(env->mlx, x, y, 0);
	else
		my_mlx_pixel_put(env->mlx, x, y,
			(((i << RED) + (i << GREEN) + (i << BLUE)) & 0xFFFFFF));
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
