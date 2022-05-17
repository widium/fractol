/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 08:54:46 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/17 16:38:44 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "fractol.h"

// void    zoom(t_data *a, int x, int y, double i)
// {
//     double    w;
//     double    h;
//     double    new_w;
//     double    new_h;

//     w = (a->view.xmax - a->view.xmin) / a->view.zoom;
//     h = (a->view.ymax - a->view.ymin) / a->view.zoom;
//     new_w = (a->view.xmax - a->view.xmin) / a->view.zoom / i;
//     new_h = (a->view.ymax - a->view.ymin) / a->view.zoom / i;
//     a->view.offsetx -= ((double)x / WIN_HEIGHT) * (new_w - w);
//     a->view.offsety -= ((double)y / WIN_HEIGHT) * (new_h - h);
//     a->view.zoom *= i;
// }


t_env *zoom_in_pos(t_env *env)
{
       
    double backup_w;
    double backup_h;
    double new_zoom_w;
    double new_zoom_h;


    backup_w =  env->complex_plan->real;
    backup_h = env->complex_plan->imag;

    zoom_in(env);

    new_zoom_w = env->complex_plan->real;
    new_zoom_h = env->complex_plan->imag;

    env->complex_plan->real_max -= (env->x / WIDHT - 0.5) * (new_zoom_w - backup_w) * 2;
    env->complex_plan->real_min -= (env->x / WIDHT - 0.5) * (new_zoom_w - backup_w)* 2;
    env->complex_plan->imag_max -= (env->y / HEIGHT - 0.5) * (new_zoom_h - backup_h)* 2;
    env->complex_plan->imag_min -= (env->y / HEIGHT - 0.5) * (new_zoom_h - backup_h)* 2;
    
    zoom_in(env);

    //env->complex_plan->real =  env->complex_plan->real_max - env->complex_plan->real_min;
    //env->complex_plan->imag =  env->complex_plan->imag_max - env->complex_plan->imag_min;
    //                          - (env->x / (env->zoom * 1.1));
    // env->complex_plan->imag_min = ((env->y / env->zoom) + env->complex_plan->imag_min) 
    //                         - (env->y / (env->zoom * 1.1));
    return (env);
}

t_env *zoom_out_pos(t_env *env)
{ 
    double backup_w;
    double backup_h;
    double new_zoom_w;
    double new_zoom_h;


    backup_w =  env->complex_plan->real;
    backup_h = env->complex_plan->imag;

    zoom_out(env);

    new_zoom_w = env->complex_plan->real;
    new_zoom_h = env->complex_plan->imag;

    env->complex_plan->real_max -= (env->x / WIDHT - 0.5) * (new_zoom_w - backup_w)* 2;
    env->complex_plan->real_min -= (env->x / WIDHT - 0.5) * (new_zoom_w - backup_w)* 2;
    env->complex_plan->imag_max -= (env->y / HEIGHT - 0.5) * (new_zoom_h - backup_h)* 2;
    env->complex_plan->imag_min -= (env->y / HEIGHT - 0.5) * (new_zoom_h - backup_h)* 2;

    //env->complex_plan->real =  env->complex_plan->real_max - env->complex_plan->real_min;
    //env->complex_plan->imag =  env->complex_plan->imag_max - env->complex_plan->imag_min;
   
    zoom_out(env);
    
    // env->complex_plan->real_min = ((env->x / env->zoom) + env->complex_plan->real_min) 
    //                         - (env->x / (env->zoom - (env->zoom * 1.1 - env->zoom)));
    // env->complex_plan->imag_min = ((env->y / env->zoom) + env->complex_plan->imag_min) 
    //                         - (env->y / (env->zoom - (env->zoom * 1.1 - env->zoom)));
    return (env);
}

void zoom_in(t_env *env)
{
   double backup_real;
   double backup_imag;
   double delta_real;
   double delta_img;


   
   backup_real = env->complex_plan->real;
   backup_imag = env->complex_plan->imag;

   env->complex_plan->real /= 1.1;
   env->complex_plan->imag /= 1.1;
   
   delta_real = (env->complex_plan->real - backup_real);
   delta_img = (env->complex_plan->imag - backup_imag);
   env->complex_plan->real_min -= delta_real / 2;
   env->complex_plan->real_max += delta_real / 2;
   env->complex_plan->imag_min -= delta_img / 2;
   env->complex_plan->imag_max += delta_img / 2;
   

   env->model->iter_max += 1;
   
}
void zoom_out(t_env *env)
{
    double backup_real;
   double backup_imag;
   double delta_real;
   double delta_img;


   
   backup_real = env->complex_plan->real;
   backup_imag = env->complex_plan->imag;

   env->complex_plan->real *= 1.1;
   env->complex_plan->imag *= 1.1;
   
   delta_real = (env->complex_plan->real - backup_real);
   delta_img = (env->complex_plan->imag - backup_imag);
   env->complex_plan->real_min -= delta_real / 2;
   env->complex_plan->real_max += delta_real / 2;
   env->complex_plan->imag_min -= delta_img / 2;
   env->complex_plan->imag_max += delta_img / 2;

   if (env->model->iter_max > 30)
        env->model->iter_max -= 0.25;
    // printf("center -> (%f, %fi)\n", env->complex_plan->center_real, env->complex_plan->center_imag);
}
