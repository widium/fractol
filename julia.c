/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:11:09 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/17 17:58:52 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

t_env *julia(t_env *env)
{
	int i;
	int x = -1.0;
	int y;

	env->c = complex_value(env->c, 0.3, 0.01);
	// printf("Complexe plan (%f, %fi)\n", env->complex_plan->real, env->complex_plan->imag);

	env->zoom_w = WIDHT / env->complex_plan->real;
	env->zoom_h = HEIGHT / env->complex_plan->imag;
	// printf("Zoom Complexe plan (%f, %fi)\n", env->zoom_w, env->zoom_h);
	
	while (++x < WIDHT)
	{
		y = -1.0;
		while (++y < HEIGHT)
		{
			i = 0;
			env = convert_normal_to_complex_plan(env, x, y);
			
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
