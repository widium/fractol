/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:02:21 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/09 18:14:56 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int pick_color(int i)
{
    // return ((i << 12) + (i << 10) + (i << 1));
    return (((i << RED) + (i << GREEN) + (i << BLUE)) & 0xFFFFFF);
}

// int main(void)
// {
//     printf("%x\n", pick_color(184392));
// }