/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:07:51 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/12 10:45:42 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

t_mlx *julia(t_env *env)
{
	int iter_max = 50;
	int i;
	int x = -1.0;

	
	while (++x < env->normal_plan->width)
	{
		int y = -1.0;
		while (++y < env->normal_plan->height)
		{
			i = 0;
			env = convert_normal_to_complex_plan(env, x, y);
			
			env->c = complex_value(env->c, env->index->real, env->index->imag);
			env->z_t = complex_value(env->z_t, env->index->real, env->index->imag);
			env->z_t1 = complex_value(env->z_t1, env->index->real, env->index->imag);
			
			while (i < iter_max && c_abs(env->z_t1) < 4)
			{
				// change value of fractal
				env->c->real = 0.3;
				env->c->imag = 0.01;
				
				//calculer le z_t+1
				env->z_t1 = compute_fractal(env->c, env->z_t, env->z_t1);
				//update z_t
				env->z_t = complex_value(env->z_t, env->z_t1->real, env->z_t1->imag);

				++i;
			}
			pick_color(i, iter_max, env, x, y);

		}
	}
	mlx_put_image_to_window(env->mlx->mlx, env->mlx->mlx_win, env->mlx->img, 0, 0);
	return (env->mlx);
}

