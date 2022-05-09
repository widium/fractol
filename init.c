/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:11:17 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/09 10:28:49 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_model *init_model()
{
	t_model *model;

	model = (t_model *)malloc(sizeof(t_model));
	if (!model)
		return (NULL);
	model->model = 0;
	model->iterations = 0;
	model->false_iterations = 0;
	model->empty = 0;
	model->to_much = 0;
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
// t_model *init_model()
// {
// 	t_model *model;

// 	model = (t_model *)malloc(sizeof(t_model));
// 	if (!model)
// 		return (NULL);
// 	model->model = 0;
// 	model->iterations = 0;
// 	model->false_iterations = 0;
// 	model->empty = 0;
// 	model->to_much = 0;
// 	return (model);
// }

