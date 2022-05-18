/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:11:09 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/18 20:00:30 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	*compute_fractal(t_complex *c, t_complex *z_t, t_complex *z_t1)
{
	z_t1->real = z_t->real * z_t->real - z_t->imag * z_t->imag + c->real;
	z_t1->imag = 2 * (z_t->real * z_t->imag) + c->imag;
	return (z_t1);
}

void	mandelbrot(t_env *env, int x, int y, t_complex *c)
{
	int	i;

	i = 0;
	while (i < env->model->iter_max && c_abs(env->z_t1) < 4)
	{
		env->z_t1 = compute_fractal(c, env->z_t, env->z_t1);
		env->z_t = complex_value(env->z_t, env->z_t1->real, env->z_t1->imag);
		++i;
	}
	pick_color(i, env, x, y);
}

void	julia(t_env *env, int x, int y, t_complex *const_z)
{
	int	i;

	i = 0;
	while (i < env->model->iter_max && c_abs(env->z_t1) < 4)
	{
		env->z_t1 = compute_fractal(const_z, env->z_t, env->z_t1);
		env->z_t = complex_value(env->z_t, env->z_t1->real, env->z_t1->imag);
		++i;
	}
	pick_color(i, env, x, y);
}

// env->const_z = complex_value(env->const_z, REAL_CONST, IMG_CONST);
int	fractal(int argc, char **argv)
{
	t_env	*env;

	env = create_env();
	env = check_input(argc, argv, env);
	if (!(define_status(env)))
	{
		print_status(env);
		free_all(env);
		return (0);
	}
	draw(env);
	mlx_mouse_hook(env->mlx->mlx_win, detect_mouse, env);
	mlx_key_hook(env->mlx->mlx_win, detect, env);
	mlx_loop(env->mlx->mlx);
	free_all(env);
	return (1);
}
