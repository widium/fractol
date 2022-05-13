/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:08:22 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/13 10:55:17 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

t_env *convert_normal_to_complex_plan(t_env *env, int x, int y)
{
    env->index->real = x / env->normal_plan->width * env->complex_plan->real + env->complex_plan->real_min;
	env->index->imag = y / env->normal_plan->height * env->complex_plan->imag + env->complex_plan->imag_min;
    return (env);	
}

t_env *get_position_complex_plan(t_env *env, int x, int y)
{
    env->pos_real = x / env->normal_plan->width * env->complex_plan->real + env->complex_plan->real_min;
    env->pos_imag = y / env->normal_plan->height * env->complex_plan->imag + env->complex_plan->imag_min;
    return (env);	
}

t_complex_plan *re_scale_complex_plan(t_complex_plan *complex_plan, double gamma)
{
    complex_plan->real_min *=  gamma;
    complex_plan->real_max *=  gamma;
    complex_plan->real = complex_plan->real_max - complex_plan->real_min;
    
    complex_plan->imag_max =  complex_plan->real_max;
    complex_plan->imag_min =  complex_plan->real_min;
    complex_plan->imag = complex_plan->imag_max - complex_plan->imag_min;

    return (complex_plan);
}