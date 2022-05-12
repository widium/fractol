/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:07:51 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/12 09:55:17 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"
# include <mlx.h>

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


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
			env->index->real = x / env->normal_plan->width * env->complex_plan->real + env->complex_plan->real_min;
			env->index->imag = y / env->normal_plan->height * env->complex_plan->imag + env->complex_plan->imag_min;
		
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
			if (i == iter_max)
				my_mlx_pixel_put(env->mlx, x, y, 0);
			else
				my_mlx_pixel_put(env->mlx, x, y, pick_color(i));

		}
	}
	mlx_put_image_to_window(env->mlx->mlx, env->mlx->mlx_win, env->mlx->img, 0, 0);
	return (env->mlx);
}

