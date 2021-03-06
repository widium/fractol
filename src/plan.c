/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:08:22 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/27 17:10:38 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_env	*convert_normal_to_complex_plan(t_env *env, int x, int y)
{
	env->index->real = x / env->zoom_w + env->complex_plan->real_min;
	env->index->imag = y / env->zoom_h + env->complex_plan->imag_min;
	return (env);
}

t_complex_plan	*re_scale_plan(t_complex_plan *complex_plan)
{
	complex_plan->real = complex_plan->real_max - complex_plan->real_min;
	complex_plan->imag = complex_plan->imag_max - complex_plan->imag_min;
	return (complex_plan);
}
