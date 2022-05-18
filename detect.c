/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:42:37 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/18 18:18:03 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	detect_mouse(int key_code, int x, int y, t_env *env)
{
	if (key_code == K_ZOOM_IN || key_code == K_ZOOM_OUT)
		zoom(key_code, x, y, env);
	else if (key_code == K_LEFT_CLICK)
	{
		if (env->model->name == 1)
			click(key_code, x, y, env);
	}
	return (0);
}

int	detect(int key_code, t_env *env)
{
	if (key_code >= K_LEFT && key_code <= K_DOWN)
		moove(key_code, env);
	else
		key_exit(key_code, env);
	return (0);
}
