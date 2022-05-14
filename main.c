/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:26:05 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/14 05:03:14 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int main(int argc, char **argv)
{
    int result;
    t_env *env;

    env = create_env(HEIGHT, WIDHT);
    
    // env = check_input(argc, argv, env);
    
    // print_status(env);
    
    // printf("Max = (%f)\n", env->complex_plan->real_max);
    // printf("Min = (%f)\n", env->complex_plan->real_min);
    
    julia(env);
    // mandelbrot(env);

    mlx_mouse_hook(env->mlx->mlx_win, zoom, env);
    mlx_key_hook(env->mlx->mlx_win, key_exit, env->mlx);
    mlx_loop(env->mlx->mlx);
    
}


