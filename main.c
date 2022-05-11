/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:26:05 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/11 17:56:30 by ebennace         ###   ########.fr       */
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
    // t_normal_plan *normal_plan;
    // t_mlx *img;
    // t_complex_plan *complex_plan;

    // complex_plan = create_complex_plan(-2.0, 2.0);
    env = create_env(2000.0, 2000.0);
    
    printf("Max = (%f)\n", env->complex_plan->real_max);
    printf("Min = (%f)\n", env->complex_plan->real_min);
    
    
    julia(env->mlx, env->normal_plan, env->complex_plan->real_min, env->complex_plan->real_max);

    mlx_mouse_hook(env->mlx->mlx_win, zoom, env);

    // printf("(%f, %f)\n", 
    //             env->complex_plan->real_min,
    //             env->complex_plan->real_max);
    
    // mlx_put_image_to_window(env->mlx->mlx, env->mlx->mlx_win, env->mlx->img, 0, 0);
    // // mlx_destroy_image(img->mlx, img->img);
	// // mlx_destroy_window(img->mlx, img->mlx_win);
 
        

    // // mlx_key_hook(img->mlx_win, key_exit, img);
    // // printf("IMG ---> (%p)\n", img->addr);
    mlx_loop(env->mlx->mlx);


    
}


