/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:38:58 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/27 17:07:09 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw(t_env *env)
{
	int	y;
	int	x;

	env->zoom_w = WIDHT / env->complex_plan->real;
	env->zoom_h = HEIGHT / env->complex_plan->imag;
	x = -1.0;
	while (++x < WIDHT)
	{
		y = -1.0;
		while (++y < HEIGHT)
		{
			env = convert_normal_to_complex_plan(env, x, y);
			env->c = complex_value(env->c, env->index->real, env->index->imag);
			env->z_t = complex_value(env->z_t,
					env->index->real, env->index->imag);
			env->z_t1 = complex_value(env->z_t1,
					env->index->real, env->index->imag);
			if (env->model->name == 1)
				julia(env, x, y, env->const_z);
			else if (env->model->name == 2)
				mandelbrot(env, x, y, env->c);
		}
	}
	mlx_put_image_to_window(env->mlx->mlx,
		env->mlx->mlx_win, env->mlx->img, 0, 0);
}
