/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:40:22 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/14 07:29:53 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

double delta_center(t_env *env, double pos_real, double pos_imag)
{
    double delta_real;
    double delta_imag;

    delta_real = 0 + pos_real;
    delta_imag = 0 + pos_imag;
    printf("delta -> (%f, %f)\n", delta_real, delta_imag);
    
    return (0.0);
}
