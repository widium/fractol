/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:07:51 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/11 17:54:30 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"
# include <mlx.h>

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


t_mlx *julia(t_mlx *img, 
		t_normal_plan *normal_plan,
		int plan_max, 
		int plan_min)
{
	t_complex_plan *complex_plan;
	t_index_complex *idx;
	
	t_complex *z_0;
	t_complex *z_t;
	t_complex *z_t1;
	
	int iter_max = 50;
	int i;
	

	idx = init_index_complex();
	
	complex_plan = create_complex_plan(plan_min, plan_max);
	
	z_0 = create_complex(0.0 , 0.0);
	z_t = create_complex(z_0->real , z_0->imag);
	z_t1 = create_complex(z_0->real , z_0->imag);
	

	int x = -1.0;
	while (++x < normal_plan->width)
	{
		int y = -1.0;
		while (++y < normal_plan->height)
		{
			i = 0;
			idx->real = x / normal_plan->width * complex_plan->real + complex_plan->real_min;
			idx->imag = y / normal_plan->height * complex_plan->imag + complex_plan->imag_min;
		
			z_0 = complex_value(z_0, idx->real, idx->imag);
			z_t = complex_value(z_t, idx->real, idx->imag);
			z_t1 = complex_value(z_t1,idx->real, idx->imag);
			
			while (i < iter_max && c_abs(z_t1) < 4)
			{
				// change value of fractal
				z_0->real = 0.3;
				z_0->imag = 0.01;
				
				//calculer le z_t+1
				z_t1 = compute_fractal(z_0, z_t, z_t1);
				
				//update z_t
				z_t = complex_value(z_t, z_t1->real, z_t1->imag);

				++i;
			}
			if (i == iter_max)
				my_mlx_pixel_put(img, x, y, 0);
			else
				my_mlx_pixel_put(img, x, y, pick_color(i));

		}
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (img);
}

