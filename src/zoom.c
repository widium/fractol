/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 08:54:46 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/27 17:10:49 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom_in_pos(t_env *env)
{
	double	backup_w;
	double	backup_h;
	double	new_zoom_w;
	double	new_zoom_h;

	backup_w = env->complex_plan->real;
	backup_h = env->complex_plan->imag;
	zoom_in(env);
	new_zoom_w = env->complex_plan->real;
	new_zoom_h = env->complex_plan->imag;
	env->complex_plan->real_max -= (env->x / WIDHT - 0.5)
		* (new_zoom_w - backup_w) * 2;
	env->complex_plan->real_min -= (env->x / WIDHT - 0.5)
		* (new_zoom_w - backup_w) * 2;
	env->complex_plan->imag_max -= (env->y / HEIGHT - 0.5)
		* (new_zoom_h - backup_h) * 2;
	env->complex_plan->imag_min -= (env->y / HEIGHT - 0.5)
		* (new_zoom_h - backup_h) * 2;
	zoom_in(env);
}

void	zoom_out_pos(t_env *env)
{
	double	backup_w;
	double	backup_h;
	double	new_zoom_w;
	double	new_zoom_h;

	backup_w = env->complex_plan->real;
	backup_h = env->complex_plan->imag;
	zoom_out(env);
	new_zoom_w = env->complex_plan->real;
	new_zoom_h = env->complex_plan->imag;
	env->complex_plan->real_max -= (env->x / WIDHT - 0.5)
		* (new_zoom_w - backup_w) * 2;
	env->complex_plan->real_min -= (env->x / WIDHT - 0.5)
		* (new_zoom_w - backup_w) * 2;
	env->complex_plan->imag_max -= (env->y / HEIGHT - 0.5)
		* (new_zoom_h - backup_h) * 2;
	env->complex_plan->imag_min -= (env->y / HEIGHT - 0.5)
		* (new_zoom_h - backup_h) * 2;
	zoom_out(env);
}

void	zoom_in(t_env *env)
{
	double	backup_real;
	double	backup_imag;
	double	delta_real;
	double	delta_img;

	backup_real = env->complex_plan->real;
	backup_imag = env->complex_plan->imag;
	env->complex_plan->real /= 1.1;
	env->complex_plan->imag /= 1.1;
	delta_real = (env->complex_plan->real - backup_real);
	delta_img = (env->complex_plan->imag - backup_imag);
	env->complex_plan->real_min -= delta_real / 2;
	env->complex_plan->real_max += delta_real / 2;
	env->complex_plan->imag_min -= delta_img / 2;
	env->complex_plan->imag_max += delta_img / 2;
	env->model->iter_max += ITER_ICREMENT;
}

void	zoom_out(t_env *env)
{
	double	backup_real;
	double	backup_imag;
	double	delta_real;
	double	delta_img;

	backup_real = env->complex_plan->real;
	backup_imag = env->complex_plan->imag;
	env->complex_plan->real *= 1.1;
	env->complex_plan->imag *= 1.1;
	delta_real = (env->complex_plan->real - backup_real);
	delta_img = (env->complex_plan->imag - backup_imag);
	env->complex_plan->real_min -= delta_real / 2;
	env->complex_plan->real_max += delta_real / 2;
	env->complex_plan->imag_min -= delta_img / 2;
	env->complex_plan->imag_max += delta_img / 2;
	if (env->model->iter_max > 30)
		env->model->iter_max -= ITER_ICREMENT;
}
