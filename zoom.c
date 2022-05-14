/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 08:54:46 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/14 08:55:32 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "fractol.h"

t_env *zoom_in(t_env *env)
{
    if (env->pos_real > 0)
    {
        env->complex_plan->real_min /= 1.1;
        env->complex_plan = re_scale_plan(env->complex_plan);
        // printf("droite (%f, %f)\n",
        //         env->complex_plan->real_min,
        //         env->complex_plan->real_max);
    }
    else if (env->pos_real < 0)
    {
        env->complex_plan->real_max /= 1.1;
        env->complex_plan = re_scale_plan(env->complex_plan);
        // printf("gauche (%f, %f)\n",
        //         env->complex_plan->real_min,
        //         env->complex_plan->real_max); 
    }
    if (env->pos_imag < 0)
    {
        env->complex_plan->imag_min /= 1.1;
        env->complex_plan = re_scale_plan(env->complex_plan);
        // printf("Monter (%f, %f)\n",
        //         env->complex_plan->imag_max,
        //         env->complex_plan->imag_min);
    }
    else if (env->pos_imag > 0)
    {
        env->complex_plan->imag_max /= 1.1;
        env->complex_plan = re_scale_plan(env->complex_plan);
        // printf("Descente (%f, %f)\n",
        //         env->complex_plan->imag_max,
        //         env->complex_plan->imag_min);
    }
    return (env);
}

t_env *zoom_out(t_env *env)
{
    if (env->pos_real > 0)
    {
        env->complex_plan->real_min *= 1.1;
        env->complex_plan = re_scale_plan(env->complex_plan);
        // printf("droite (%f, %f)\n",
        //         env->complex_plan->real_min,
        //         env->complex_plan->real_max);
    }
    else if (env->pos_real < 0)
    {
        env->complex_plan->real_max *= 1.1;
        env->complex_plan = re_scale_plan(env->complex_plan);
        // printf("gauche (%f, %f)\n",
        //         env->complex_plan->real_min,
        //         env->complex_plan->real_max); 
    }
    if (env->pos_imag < 0)
    {
        env->complex_plan->imag_min *= 1.1;
        env->complex_plan = re_scale_plan(env->complex_plan);
        // printf("Monter (%f, %f)\n",
        //         env->complex_plan->imag_max,
        //         env->complex_plan->imag_min);
    }
    else if (env->pos_imag > 0)
    {
        env->complex_plan->imag_max *= 1.1;
        env->complex_plan = re_scale_plan(env->complex_plan);
        // printf("Descente (%f, %f)\n",
        //         env->complex_plan->imag_max,
        //         env->complex_plan->imag_min);
    }
    return (env);
}