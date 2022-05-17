/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:26:05 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/17 12:47:34 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int main(int argc, char **argv)
{
    int result;
    t_env *env;

    env = create_env();
    
    // env = check_input(argc, argv, env);
    
    // if (!(define_status(env)))
    // {
    //     print_status(env);
    //     return (0);
    // }
    julia(env);
    // mandelbrot(env);
    mlx_mouse_hook(env->mlx->mlx_win, zoom, env);
    mlx_key_hook(env->mlx->mlx_win, moove, env);
    mlx_loop(env->mlx->mlx);
    
}


