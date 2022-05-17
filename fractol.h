/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:07:45 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/17 12:47:32 by ebennace         ###   ########.fr       */
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
# define ITER_MAX 100
# define HEIGHT 500.0
# define WIDHT 500.0
# define ZOOM 100



typedef struct s_input
{
    int false_iterations;
    int empty;
    int to_much;
}       t_input;

typedef struct s_model
{
    int name;
    int iter_max;

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
    double center_real;
    double center_imag;
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
    t_input *input;
    t_mlx *mlx;
    t_model *model;
    t_complex_plan *complex_plan;
    t_normal_plan *normal_plan;
    t_index_complex *index;
    t_complex *z_t1;
    t_complex *z_t;
    t_complex *c;
    double x;
    double y;
    double zoom_w;
    double zoom_h;
    double zoom;
    
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
t_env *create_env();


void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

int zoom(int key_code, int x, int y, t_env *env);
t_env *zoom_out_pos(t_env *env);
t_env *zoom_in_pos(t_env *env);
void zoom_out(t_env *env);
void zoom_in(t_env *env);
void re_scale_plan_with_mouse_pos(t_env *env, int x, int y);
void zoom_test(t_env *env, int x, int y, double gamma);
int moove(int key_code, t_env *env);
int key_exit(int key_code, t_mlx *mlx);


t_env *convert_normal_to_complex_plan(t_env *env, int x, int y);
t_env *get_position_complex_plan(t_env *env, int x, int y);
t_complex *complex_value(t_complex *z, double real, double imag);
t_complex *compute_fractal(t_complex *c, t_complex *z_t, t_complex *z_t1);

t_complex_plan *re_scale_complex_plan(t_complex_plan *complex_plan, double gamma);
t_complex_plan *re_scale_plan(t_complex_plan *complex_plan);

double c_abs(t_complex *z);
double delta_center(t_env *env, double pos_real, double pos_imag);

t_env *julia(t_env *env);
t_env *mandelbrot(t_env *env);

int define_status(t_env *env);
int str_comp(char *first, char *second);
int check_argc(int argc);
int is_digit(char *str);
int	check_name_fractal(char *argv);
int get_iterations(char *argv);
t_env *check_input(int argc, char **argv, t_env *env);
void print_status(t_env *env);

void pick_color(int i, int iter_max, t_env *env, int x, int y);

#endif