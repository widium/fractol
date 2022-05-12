/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:52:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/12 09:56:49 by ebennace         ###   ########.fr       */
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
    (void) x;
    (void) y;
	//printf("KEYCODE 2 == (%d)\n", key_code);
	if (key_code == K_ZOOM_IN)
	{
        printf("ZOOM IN\n");
        env->complex_plan = re_scale_complex_plan(env->complex_plan, 0.9);
        printf("(%f, %f)\n", 
                env->complex_plan->real_min,
                env->complex_plan->real_max);
        julia(env);
	}
	else if (key_code == K_ZOOM_OUT)
    {
       printf("ZOOM OUT\n");
       printf("(%f, %f)\n", 
                env->complex_plan->real_min,
                env->complex_plan->real_max);
       env->complex_plan = re_scale_complex_plan(env->complex_plan, 1.1);
       julia(env);
    }
		
    
    return (0);
}