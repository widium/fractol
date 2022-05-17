/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:52:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/17 18:01:59 by ebennace         ###   ########.fr       */
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
    // printf("Normal plan Position (%d, %d)\n", x , y);
    // printf("Complex plan Position (%f, %f)\n", env->pos_real ,env->pos_imag);
    env->x = x;
    env->y = y;
    
	if (key_code == K_ZOOM_IN)
	{ 
        zoom_in_pos(env);
        julia(env);
        // mandelbrot(env);
	}
	else if (key_code == K_ZOOM_OUT)
    {
        zoom_out_pos(env);
       julia(env);
        // mandelbrot(env);
    }
    return (0);
}

int moove(int key_code, t_env *env)
{   
    if (key_code == K_UP)
    {
        printf("Monter\n");
        env->complex_plan->imag_max += 0.001 * env->zoom_h;
        env->complex_plan->imag_min += 0.001 * env->zoom_h;
    }
    if (key_code == K_LEFT)
    {
        printf("Gauche\n");
        env->complex_plan->real_min -= 0.001 * env->zoom_w;
        env->complex_plan->real_max -= 0.001 * env->zoom_w;
    }
    if (key_code == K_DOWN)
    {
        printf("Descendre\n");
        env->complex_plan->imag_max -= 0.001 * env->zoom_h;
        env->complex_plan->imag_min -= 0.001 * env->zoom_h;
    }
    if (key_code == K_RIGHT)
    {
        printf("Droite\n");
        env->complex_plan->real_max += 0.001 * env->zoom_w;
        env->complex_plan->real_min += 0.001 * env->zoom_w;  
    }
    julia(env);
    return (0);
}