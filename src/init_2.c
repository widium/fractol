/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:22:38 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/27 17:07:25 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_mlx	*create_imag(int height, int widht)
{
	t_mlx	*img;

	img = (t_mlx *)malloc(sizeof(t_mlx));
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, widht, height, "Fract-ol");
	img->img = mlx_new_image(img->mlx, widht, height);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	img->is_pressed = 0;
	return (img);
}

t_normal_plan	*init_normal_plan(void)
{
	t_normal_plan	*plan;

	plan = (t_normal_plan *)malloc(sizeof(t_normal_plan));
	if (!plan)
		return (NULL);
	plan->height = 0.0;
	plan->width = 0.0;
	return (plan);
}

t_index_complex	*init_index_complex(void)
{
	t_index_complex	*index;

	index = (t_index_complex *)malloc(sizeof(t_index_complex));
	if (!index)
		return (NULL);
	index->real = 0.0;
	index->imag = 0.0;
	return (index);
}

t_env	*create_env(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->complex_plan = create_complex_plan(-2.0, 2.0);
	env->normal_plan = create_normal_plan(HEIGHT, WIDHT);
	env->mlx = create_imag((int)HEIGHT, (int)WIDHT);
	env->index = init_index_complex();
	env->z_t1 = create_complex(0.0, 0.0);
	env->z_t = create_complex(0.0, 0.0);
	env->c = create_complex(0.0, 0.0);
	env->const_z = create_complex(0.0, 0.0);
	env->model = init_model();
	env->input = init_input();
	env->x = 0.0;
	env->y = 0.0;
	env->zoom_w = 0.0;
	env->zoom_h = 0.0;
	env->zoom = ZOOM;
	return (env);
}
