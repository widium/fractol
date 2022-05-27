/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:52:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/27 17:07:21 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_exit(int key_code, t_env *env)
{
	if (key_code == K_ESC)
	{
		mlx_destroy_image(env->mlx->mlx, env->mlx->img);
		mlx_destroy_window(env->mlx->mlx, env->mlx->mlx_win);
		exit(0);
	}
	return (0);
}

int	zoom(int key_code, int x, int y, t_env *env)
{
	env->x = x;
	env->y = y;
	if (key_code == K_ZOOM_IN)
	{
		zoom_in_pos(env);
		draw(env);
	}
	else if (key_code == K_ZOOM_OUT)
	{
		zoom_out_pos(env);
		draw(env);
	}
	return (0);
}

// printf("(%f, %f)\n", env->index->real, env->index->imag);
int	click(int key_code, int x, int y, t_env *env)
{
	env = convert_normal_to_complex_plan(env, x, y);
	env->const_z->real = env->index->real;
	env->const_z->imag = env->index->imag;
	draw(env);
	return (0);
}

int	moove(int key_code, t_env *env)
{
	if (key_code == K_UP)
	{
		env->complex_plan->imag_max += 0.001 * env->zoom_h;
		env->complex_plan->imag_min += 0.001 * env->zoom_h;
	}
	if (key_code == K_LEFT)
	{
		env->complex_plan->real_min -= 0.001 * env->zoom_w;
		env->complex_plan->real_max -= 0.001 * env->zoom_w;
	}
	if (key_code == K_DOWN)
	{
		env->complex_plan->imag_max -= 0.001 * env->zoom_h;
		env->complex_plan->imag_min -= 0.001 * env->zoom_h;
	}
	if (key_code == K_RIGHT)
	{
		env->complex_plan->real_max += 0.001 * env->zoom_w;
		env->complex_plan->real_min += 0.001 * env->zoom_w;
	}
	draw(env);
	return (0);
}
