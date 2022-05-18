/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:56:17 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/18 19:59:09 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	free_all(t_env *env)
{
	free(env->complex_plan);
	free(env->normal_plan);
	free(env->mlx);
	free(env->index);
	free(env->z_t1);
	free(env->z_t);
	free(env->c);
	free(env->const_z);
	free(env->model);
	free(env->input);
	free(env);
	return (0);
}
