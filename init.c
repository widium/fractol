/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:11:17 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/18 18:27:46 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_input	*init_input(void)
{
	t_input	*input;

	input = (t_input *)malloc(sizeof(t_input));
	if (!input)
		return (NULL);
	input->empty = 0;
	input->false_iterations = 0;
	input->to_much = 0;
	return (input);
}

t_model	*init_model(void)
{
	t_model	*model;

	model = (t_model *)malloc(sizeof(t_model));
	if (!model)
		return (NULL);
	model->name = 0;
	model->iter_max = ITER_MAX;
	return (model);
}

t_complex	*init_complex(void)
{
	t_complex	*complex;

	complex = (t_complex *)malloc(sizeof(t_complex));
	if (!complex)
		return (NULL);
	complex->real = 0.0;
	complex->imag = 0.0;
	return (complex);
}

t_complex_plan	*init_complex_plan(void)
{
	t_complex_plan	*plan;

	plan = (t_complex_plan *)malloc(sizeof(t_complex_plan));
	if (!plan)
		return (NULL);
	plan->imag_max = 0.0;
	plan->imag_min = 0.0;
	plan->imag = 0.0;
	plan->real_max = 0.0;
	plan->real_min = 0.0;
	plan->real = 0.0;
	plan->center_imag = 0.0;
	plan->center_real = 0.0;
	return (plan);
}
