/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:26:05 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/12 10:54:51 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"


t_complex_plan *re_scale_complex_plan(t_complex_plan *complex_plan, double gamma)
{
    
    complex_plan->imag_max *=  gamma;
    complex_plan->real_max *=  gamma;
    
    complex_plan->real_min *=  gamma;
    complex_plan->imag_min *=  gamma;

    return (complex_plan);
}
int main(void)
{
    int result;
    t_env *env;

    env = create_env(HEIGHT, WIDHT, ITER_MAX);
    
    printf("Max = (%f)\n", env->complex_plan->real_max);
    printf("Min = (%f)\n", env->complex_plan->real_min);
    
    julia(env);

    mlx_mouse_hook(env->mlx->mlx_win, zoom, env);
    mlx_key_hook(env->mlx->mlx_win, key_exit, env->mlx);
    mlx_loop(env->mlx->mlx);
    
}


