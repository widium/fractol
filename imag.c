/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:07:51 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/06 21:21:25 by ebennace         ###   ########.fr       */
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


// t_complex *compute_mandelbrot(t_complex *z_t)
// {
// 	t_complex *z_0;

// 	z_0 = create_complex(z_t->real , z_t->imag);
	
// 	z_t1->real = 
// }

int main(void)
{
	t_complex *z;
	t_complex *zt;
	t_complex *zt1;
	z = create_complex(0.0 , 1.0);
	zt = create_complex(z->real , z->imag);
	zt1 = create_complex(z->real , z->imag);
	
	// printf("(%f, %fi)\n", z->real, z->imag);
	// printf("(%f, %fi)\n", zt->real, zt->imag);
	// printf("(%f, %fi)\n", zt1->real, zt1->imag);
	
	int i = 0;
	while (i++ < 5)
	{
		//compute mandelbrot z_t+1 = zt**2 + z_0
		zt1->real = zt->real * zt->real - zt->imag * zt->imag + z->real;
		zt1->imag = 2*(zt->real * zt->imag) + z->imag;

		//update z_t
		zt->real = zt1->real;
		zt->imag = zt1->imag;
		 
		printf("(%f, %fi)\n", zt1->real, zt1->imag);
	}
	
}

// int	main(void)
// {
// 	t_mlx	*img;
// 	t_complex_plan *complex_plan;
// 	t_normal_plan *normal_plan;
// 	t_complex *z;
// 	t_complex *new_z;
	
// 	int iter_max = 1;
// 	int i;
	
	
// 	double real = 0.0;
// 	double imag = 0.0;
	
//     img = (t_mlx *)malloc(sizeof(t_mlx));
// 	complex_plan = create_complex_plan(-2.0, 2.0);
// 	normal_plan = create_normal_plan(1000.0, 1000.0);
// 	z = create_complex(0, 0);
// 	new_z = create_complex(0, 0);
	
// 	img->mlx = mlx_init();
// 	img->mlx_win = mlx_new_window(img->mlx, (int)normal_plan->width, (int)normal_plan->height, "Hello world!");
// 	img->img = mlx_new_image(img->mlx, (int)normal_plan->width, (int)normal_plan->height);
// 	img->addr = mlx_get_data_addr(img->img, 
// 								&img->bits_per_pixel, 
// 								&img->line_length,
// 								&img->endian);

// 	int x = -1.0;
// 	while (++x < normal_plan->width)
// 	{
// 		int y = -1.0;
// 		while (++y < normal_plan->height)
// 		{
// 			i = 0;
// 			real = x / normal_plan->width * complex_plan->real + complex_plan->real_min;
// 			imag = y / normal_plan->height * complex_plan->imag + complex_plan->imag_min;
		
// 			z->real = real;
// 			z->imag = imag;
				
// 			new_z->real = z->real;
// 			new_z->imag = z->imag;
// 			while (i < iter_max && (new_z->real * new_z->real + new_z->imag * new_z->imag) < 4)
// 			{
// 				//calculer le z_t+1
// 				printf("befor (%f, %fi)\n", new_z->real, new_z->imag);
// 				new_z->real = z->real * z->real - 0.75;
// 				new_z->imag = z->imag * z->imag - z->imag;
// 				printf("after (%f, %fi)\n", new_z->real, new_z->imag);
				
// 				//garder la valeur du z_t
// 				z->real = new_z->real;
// 				z->imag = new_z->imag;
				
// 				++i;
// 			}
// 			if (i == iter_max)
// 				my_mlx_pixel_put(img, x, y, 0);
// 			else
// 				my_mlx_pixel_put(img, x, y, 0x00FFFF);

// 		}
// 	}
// 	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
// 	mlx_loop(img->mlx);

// }