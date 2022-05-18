/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:11:09 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/18 17:23:28 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"
 
 void julia(t_env *env, int x, int y, t_complex *const_z)
{
	int i;
    i = 0;
    
    while (i < env->model->iter_max && c_abs(env->z_t1) < 4)
    {
        //calculer le z_t+1
        env->z_t1 = compute_fractal(const_z, env->z_t, env->z_t1);
        //update z_t
        env->z_t = complex_value(env->z_t, env->z_t1->real, env->z_t1->imag);
        ++i;
    }
    pick_color(i, env, x, y);

	
}

void mandelbrot(t_env *env, int x, int y, t_complex *c)
{
    int i;

    i = 0;
    while (i < env->model->iter_max && c_abs(env->z_t1) < 4)
    {
        //calculer le z_t+1
        env->z_t1 = compute_fractal(c, env->z_t, env->z_t1);
        //update z_t
        env->z_t = complex_value(env->z_t, env->z_t1->real, env->z_t1->imag);
        ++i;
    }
    pick_color(i, env, x, y);

}
