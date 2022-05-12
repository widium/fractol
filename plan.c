/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:08:22 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/12 10:33:00 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

t_env *convert_normal_to_complex_plan(t_env *env, int x, int y)
{
    env->index->real = x / env->normal_plan->width * env->complex_plan->real + env->complex_plan->real_min;
	env->index->imag = y / env->normal_plan->height * env->complex_plan->imag + env->complex_plan->imag_min;
    return (env);	
}