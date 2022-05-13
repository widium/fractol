/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:40:22 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/13 14:49:40 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

double delta_center(double position, double center)
{
    return (position - center);
}