/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:51:40 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/18 17:28:18 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "fractol.h"

# ifdef __gnu_linux__
#  define K_ESC 65307
#  define K_UP 65362
#  define K_DOWN 65364
#  define K_LEFT 65361
#  define K_RIGHT 65363
#  define K_W 119
#  define K_S 115
#  define K_A 97
#  define K_D 100
#  define K_P 112
#  define K_MINUS 45
#  define K_PLUS 113
#  define K_R 114
#  define K_U 117
#  define K_J 106
#  define K_I 105
#  define K_K 107
#  define K_O 111
#  define K_L 108
#  define K_ZOOM_IN 4
#  define K_ZOOM_OUT 5
#  define K_LEFT_CLICK 1
#  define K_RIGHT_CLICK 3
# elif __APPLE__
#  define K_ZOOM_IN 4
#  define K_ZOOM_OUT 5
#  define K_LEFT_CLICK 1
#  define K_RIGHT_CLICK 3
#  define K_ESC 53
#  define K_UP 126
#  define K_DOWN 125
#  define K_LEFT 123
#  define K_RIGHT 124
#  define K_W 13
#  define K_S 1
#  define K_A 0
#  define K_D 2
#  define K_P 35
#  define K_MINUS 27
#  define K_PLUS 24
#  define K_R 15
#  define K_U 32
#  define K_J 38
#  define K_I 34
#  define K_K 40
#  define K_O 31
#  define K_L 37
#  define KEYDOWN 2
#  define KEYUP 3
#  define MOUSE_DOWN  4
#  define MOUSE_UP  5
#  define ON_MOUSEMOVE  6
#  define ON_EXPOSE 12
#  define ON_DESTROY 17
# endif

#endif