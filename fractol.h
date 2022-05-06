/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:07:45 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/06 15:32:48 by ebennace         ###   ########.fr       */
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
# include <math.h>


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
    double real;
    double imag; 
}       t_complex;


typedef struct s_complex_plan
{
    double imag_max;
    double imag_min;
    double imag;
    double real_max;
    double real_min;
    double real;
}       t_complex_plan;

typedef struct s_normal_plan
{
    double height;
    double width;
}       t_normal_plan;


t_model *init_model();
t_complex *init_complex();
t_complex_plan *init_complex_plan();
t_normal_plan *init_normal_plan();


t_normal_plan *create_normal_plan(double height, double width);
t_complex_plan *create_complex_plan(double min, double max);
t_complex *create_complex(double real, double imag);

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);


int str_comp(char *first, char *second);
int check_argc(int argc);
int is_digit(char *str);
int	check_name_fractal(char *argv);
int get_iterations(char *argv);
t_model *check_input(int argc, char **argv);

#endif