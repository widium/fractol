/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:11:17 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/14 05:20:26 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_input *init_input()
{
	t_input *input;

	input = (t_input *)malloc(sizeof(t_input));
	if (!input)
		return (NULL);
	input->empty = 0;
	input->false_iterations = 0;
	input->to_much = 0;
	return (input);
}

t_mlx *create_imag(int height, int widht)
{
	t_mlx	*img;
	img = (t_mlx *)malloc(sizeof(t_mlx));

	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, widht, height, "Hello world!");
	img->img = mlx_new_image(img->mlx, widht, height);
	img->addr = mlx_get_data_addr(img->img, 
								&img->bits_per_pixel, 
								&img->line_length,
								&img->endian);
	return (img);
}

t_model *init_model()
{
	t_model *model;

	model = (t_model *)malloc(sizeof(t_model));
	if (!model)
		return (NULL);
	model->name = 0;
	model->iter_max = ITER_MAX;
	return (model);
}

t_complex *init_complex()
{
	t_complex	*complex;

	complex = (t_complex *)malloc(sizeof(t_complex));
	if (!complex)
		return (NULL);
	complex->real = 0.0;
	complex->imag = 0.0;
	return (complex);
}

t_complex_plan *init_complex_plan()
{
	t_complex_plan *plan;

	plan = (t_complex_plan *)malloc(sizeof(t_complex_plan));
	if (!plan)
		return (NULL);
	plan->imag_max = 0.0;
    plan->imag_min = 0.0;
    plan->imag = 0.0;
    plan->real_max = 0.0;
    plan->real_min = 0.0;
    plan->real = 0.0;
	plan->zoom = 1.0;
	return (plan);
}

t_normal_plan *init_normal_plan()
{
	t_normal_plan *plan;
	
	plan = (t_normal_plan *)malloc(sizeof(t_normal_plan));
	if (!plan)
		return (NULL);
	plan->height = 0.0;
	plan->width = 0.0;
	return (plan);
}

t_index_complex *init_index_complex()
{
	t_index_complex *index;
	
	index = (t_index_complex *)malloc(sizeof(t_index_complex));
	if (!index)
		return (NULL);
	index->real = 0.0;
	index->imag = 0.0;
	return (index);	
}

t_env *create_env(int height, int widht)
{
	t_env *env;
	
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->complex_plan = create_complex_plan(-2.0, 2.0);
	env->normal_plan = create_normal_plan(height, widht);
	env->mlx =  create_imag((int)env->normal_plan->height, (int)env->normal_plan->width);
	env->index = init_index_complex();
	env->z_t1 = create_complex(0.0, 0.0);
	env->z_t = create_complex(0.0, 0.0);
	env->c = create_complex(0.0, 0.0);
	env->model = init_model();
	env->input = init_input();
	env->pos_real = 0.0;
	env->pos_imag = 0.0;
	return (env);
}
