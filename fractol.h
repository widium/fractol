/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:07:45 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/05 18:32:43 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <mlx.h>
# include "libft/libft.h"


typedef struct s_model
{
    int model;
    int iterations;
    int false_iterations;
    int empty;
    int to_much;

}   t_model;


typedef struct	s_mlx 
{
    void    *mlx;
    void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct s_complex
{
    int real;
    int imag; 
}       t_complex;


typedef struct s_complex_plan
{
    int imag_max;
    int imag_min;
    int imag;
    int real_max;
    int real_min;
    int real;
}       t_complex_plan;

typedef struct s_normal_plan
{
    int height;
    int widht;
}       t_normal_plan;


t_model *init_model();
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);


#endif