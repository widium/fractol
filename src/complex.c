/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:08:32 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/27 17:06:56 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex	*create_complex(double real, double imag)
{
	t_complex	*complex;

	complex = init_complex();
	complex->real = real;
	complex->imag = imag;
	return (complex);
}

t_complex_plan	*create_complex_plan(double min, double max)
{
	t_complex_plan	*plan;

	plan = init_complex_plan();
	plan->imag_min = min;
	plan->imag_max = max;
	plan->imag = max - min;
	plan->real_min = min;
	plan->real_max = max;
	plan->real = max - min;
	plan->center_imag = (plan->imag_min + plan->imag_max) / 2.0 ;
	plan->center_real = (plan->real_min + plan->real_max) / 2.0;
	return (plan);
}

t_normal_plan	*create_normal_plan(double height, double width)
{
	t_normal_plan	*plan;

	plan = init_normal_plan();
	plan->height = height;
	plan->width = width;
	return (plan);
}

t_complex	*complex_value(t_complex *z, double real, double imag)
{
	z->real = real;
	z->imag = imag;
	return (z);
}

double	c_abs(t_complex *z)
{
	return (z->real * z->real + z->imag * z->imag);
}
