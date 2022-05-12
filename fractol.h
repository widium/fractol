/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:07:45 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/12 09:47:51 by ebennace         ###   ########.fr       */
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
#include "key.h"


# define RED 12
# define GREEN 10
# define BLUE 1


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

typedef struct s_index_complex
{
    double real;
    double imag;
}       t_index_complex;

typedef struct s_env
{
    t_mlx *mlx;
    //t_model *model;
    t_complex_plan *complex_plan;
    t_normal_plan *normal_plan;
    t_index_complex *index;
    t_complex *z_t1;
    t_complex *z_t;
    t_complex *c;
    
}           t_env;


t_model *init_model();
t_complex *init_complex();
t_index_complex *init_index_complex();
t_complex_plan *init_complex_plan();
t_normal_plan *init_normal_plan();


//---Init Struct-----//
t_normal_plan *create_normal_plan(double height, double width);
t_complex_plan *create_complex_plan(double min, double max);
t_complex *create_complex(double real, double imag);
t_mlx *create_imag(int height, int widht);
t_env *create_env(int height, int widht);


void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

int zoom(int key_code, int x, int y, t_env *env);
int key_exit(int key_code, t_mlx *mlx);


t_complex *complex_value(t_complex *z, double real, double imag);
t_complex *compute_fractal(t_complex *c, t_complex *z_t, t_complex *z_t1);
t_complex_plan *re_scale_complex_plan(t_complex_plan *complex_plan, double gamma);
double c_abs(t_complex *z);

t_mlx *julia(t_env *env);

int str_comp(char *first, char *second);
int check_argc(int argc);
int is_digit(char *str);
int	check_name_fractal(char *argv);
int get_iterations(char *argv);
t_model *check_input(int argc, char **argv);


int pick_color(int i);

#endif