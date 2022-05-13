/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:55:38 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/13 10:21:09 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

t_env *mandelbrot(t_env *env)
{
	int i;
	int x = -1.0;
	int y;

	
	while (++x < env->normal_plan->width)
	{
		y = -1.0;
		while (++y < env->normal_plan->height)
		{
			i = 0;
			env = convert_normal_to_complex_plan(env, x, y);
			
			env->c = complex_value(env->c, env->index->real, env->index->imag);
			env->z_t = complex_value(env->z_t, env->index->real, env->index->imag);
			env->z_t1 = complex_value(env->z_t1, env->index->real, env->index->imag);
			
			while (i < env->model->iter_max && c_abs(env->z_t1) < 4)
			{
				//calculer le z_t+1
				env->z_t1 = compute_fractal(env->c, env->z_t, env->z_t1);
				//update z_t
				env->z_t = complex_value(env->z_t, env->z_t1->real, env->z_t1->imag);
				++i;
			}
			pick_color(i, env->model->iter_max, env, x, y);

		}
	}
	mlx_put_image_to_window(env->mlx->mlx, env->mlx->mlx_win, env->mlx->img, 0, 0);
	return (env);
}