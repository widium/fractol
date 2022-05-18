/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:26:05 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/18 17:34:56 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int main(int argc, char **argv)
{
    int result;
    t_env *env;

    env = create_env();
    
    env = check_input(argc, argv, env);
    
    if (!(define_status(env)))
    {
        print_status(env);
        return (0);
    }
    draw(env);
    mlx_mouse_hook(env->mlx->mlx_win, detect_mouse, env);
    // mlx_mouse_hook(env->mlx->mlx_win, zoom, env);
    // mlx_hook(env->mlx->mlx_win, 6, 1L << 8, click, env);
    mlx_key_hook(env->mlx->mlx_win, detect, env);
    
    // mlx_hook(env->mlx->mlx_win, 5, 1L << 3, &release, all);
    mlx_loop(env->mlx->mlx);
    
}


