/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:08:32 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/06 15:26:20 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "fractol.h"

t_complex *create_complex(double real, double imag)
{
    t_complex *complex;

    complex = init_complex();

    complex->real = real;
    complex->imag = imag;

    // printf("(%d, %di)\n", complex->real, complex->imag);
    return (complex);
}

t_complex_plan *create_complex_plan(double min, double max)
{
    t_complex_plan *plan;

    plan = init_complex_plan();
    
    plan->imag_min = min;
    plan->imag_max = max;
    plan->imag = max - min;
    plan->real_min = min;
    plan->real_max = max;
    plan->real = max - min;

    // printf(" Real : (%d)--------(%d)\n", plan->real_min, plan->real_max);
    // printf(" Imag : (%d)\n         |\n         |\n         |\n         |\n       (%d)\n", plan->imag_max, plan->imag_min);
    return (plan);
}

t_normal_plan *create_normal_plan(double height, double width)
{
    t_normal_plan *plan;

    plan = init_normal_plan();
    
    plan->height = height;
    plan->width = width;
    return (plan);

    // printf(" width : (%d)--------(%d)\n", plan->height - plan->height, plan->height);
    // printf(" height : (%d)\n         |\n         |\n         |\n         |\n       (%d)\n", plan->width - plan->width, plan->width);
}
// int main(void)
// {
//     create_complex(3, 6);
//     create_complex_plan(-2 , 2);
//     create_normal_plan(1920, 1080);
// }