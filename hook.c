/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:52:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/14 09:16:19 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int key_exit(int key_code, t_mlx *mlx)
{
	if (key_code == K_ESC)
	{
		printf("ESCAPE\n");
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	}
	return (0);
}

int zoom(int key_code, int x, int y, t_env *env)
{
    double w;
    double h;
    
    double new_h;
    double new_w;
    // printf("Normal plan Position (%f)\n", fabs(x + y));
    env = get_position_complex_plan(env, x, y);
    //printf("Complex plan Position (%f, %f)\n", env->pos_real ,env->pos_imag);
    
	//printf("KEYCODE 2 == (%d)\n", key_code);
	if (key_code == K_ZOOM_IN)
	{       
        env = zoom_in(env);
        // julia(env);
        mandelbrot(env);
        env->complex_plan = re_scale_complex_plan(env->complex_plan, 0.9);
	}
	else if (key_code == K_ZOOM_OUT)
    {
       env = zoom_out(env);
    //    julia(env);
        mandelbrot(env);
       env->complex_plan = re_scale_complex_plan(env->complex_plan, 1.1);
    //    printf("Position -> (%d)\n", mlx_mouse_get_pos(env->mlx->mlx, env->mlx->mlx_win, (int)WIDHT, (int)HEIGHT));
    }
    return (0);
}

int moove(int key_code, t_env *env)
{
    printf("Complex plan (%f, %f)\n", env->complex_plan->real_min ,env->complex_plan->real_max);
    
    if (key_code == K_UP)
    {
        printf("Monter\n");
        env->complex_plan->imag_min -= 0.2;
        env->complex_plan = re_scale_plan(env->complex_plan);
    }
    if (key_code == K_LEFT)
    {
        printf("Gauche\n");
        env->complex_plan->real_min -= 0.2;
        env->complex_plan = re_scale_plan(env->complex_plan);
    }
    if (key_code == K_DOWN)
    {
        printf("Descendre\n");
        env->complex_plan->imag_max -= 0.2;
        env->complex_plan = re_scale_plan(env->complex_plan);
    }
    if (key_code == K_RIGHT)
    {
        printf("Droite\n");
        env->complex_plan->real_max -= 0.2;
        env->complex_plan = re_scale_plan(env->complex_plan);
    }
    julia(env);
    return (0);
}