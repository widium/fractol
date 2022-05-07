/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:07:51 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/07 19:56:00 by ebennace         ###   ########.fr       */
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


t_complex *compute_fractal(t_complex *c, t_complex *z_t, t_complex *z_t1)
{
	z_t1->real = z_t->real * z_t->real - z_t->imag * z_t->imag + c->real;
	z_t1->imag = 2*(z_t->real * z_t->imag) + c->imag;

	return(z_t1);

}

// int main(void)
// {
// 	t_complex *z_0;
// 	t_complex *z_t;
// 	t_complex *z_t1;
// 	z_0 = create_complex(0.0 , 1.0);
// 	z_t = create_complex(z_0->real , z_0->imag);
// 	z_t1 = create_complex(z_0->real , z_0->imag);
	
	
// 	int i = 0;
// 	while (i++ < 5)
// 	{
// 		//compute mandelbrot z_t+1 = zt**2 + z_0
// 		z_t1 = compute_fractal(z_0, z_t, z_t1);

// 		//update z_t
// 		z_t->real = z_t1->real;
// 		z_t->imag = z_t1->imag;
		 
// 		printf("(%f, %fi)\n", z_t1->real, z_t1->imag);
// 	}
	
// }

int	main(void)
{
	t_mlx	*img;
	t_complex_plan *complex_plan;
	t_normal_plan *normal_plan;
	
	t_complex *z_0;
	t_complex *z_t;
	t_complex *z_t1;
	
	int iter_max = 100;
	int i;
	
	
	double real = 0.0;
	double imag = 0.0;
	
    img = (t_mlx *)malloc(sizeof(t_mlx));
	complex_plan = create_complex_plan(-2.0, 2.0);
	normal_plan = create_normal_plan(1000.0, 1000.0);
	
	z_0 = create_complex(0.0 , 0.0);
	z_t = create_complex(z_0->real , z_0->imag);
	z_t1 = create_complex(z_0->real , z_0->imag);
	
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, (int)normal_plan->width, (int)normal_plan->height, "Hello world!");
	img->img = mlx_new_image(img->mlx, (int)normal_plan->width, (int)normal_plan->height);
	img->addr = mlx_get_data_addr(img->img, 
								&img->bits_per_pixel, 
								&img->line_length,
								&img->endian);

	int x = -1.0;
	while (++x < normal_plan->width)
	{
		int y = -1.0;
		while (++y < normal_plan->height)
		{
			i = 0;
			real = x / normal_plan->width * complex_plan->real + complex_plan->real_min;
			imag = y / normal_plan->height * complex_plan->imag + complex_plan->imag_min;
		
			z_0->real = real;
			z_0->imag = imag;

			z_t->real = z_0->real;
			z_t->imag = z_0->imag;
			
			z_t1->real = z_0->real;
			z_t1->imag = z_0->imag;
			
			while (i < iter_max && (z_t1->real * z_t1->real + z_t1->imag * z_t1->imag) < 4)
			{
				//change value of fractal
				z_0->real = -0.79;
				z_0->imag = 0.15;
				
				//calculer le z_t+1
				z_t1 = compute_fractal(z_0, z_t, z_t1);
				
				//update z_t
				z_t->real = z_t1->real;
				z_t->imag = z_t1->imag;
				
				++i;
			}
			if (i == iter_max)
				my_mlx_pixel_put(img, x, y, 0);
			else
				my_mlx_pixel_put(img, x, y, 0x00FFFFFF);

		}
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_loop(img->mlx);

}