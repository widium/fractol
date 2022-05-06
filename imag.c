/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:07:51 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/06 15:31:28 by ebennace         ###   ########.fr       */
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

int	main(void)
{
	t_mlx	*img;
	t_complex_plan *complex_plan;
	t_normal_plan *normal_plan;
	t_complex *z;
	
	double idx_real = 0.0;
	double idx_imag = 0.0;
    img = (t_mlx *)malloc(sizeof(t_mlx));
	complex_plan = create_complex_plan(-2.0, 2.0);
	normal_plan = create_normal_plan(1080.0, 1920.0);
	
	// img->mlx = mlx_init();
	// img->mlx_win = mlx_new_window(img->mlx, 1920, 1080, "Hello world!");
	// img->img = mlx_new_image(img->mlx, 1920, 1080);
	// img->addr = mlx_get_data_addr(img->img, 
	// 							&img->bits_per_pixel, 
	// 							&img->line_length,
	// 							&img->endian);

	int x = -1.0;
	while (++x < normal_plan->width)
	{
		int y = -1.0;
		while (++y < normal_plan->height)
		{
			z = create_complex(x, y);
			idx_real = x / normal_plan->width * complex_plan->real + complex_plan->real_min;
			idx_imag = y / normal_plan->height * complex_plan->imag + complex_plan->imag_min;
			// printf("(%d) / 1920 * (%d) + (%d)\n", x, complex_plan->real, complex_plan->real_min);
			// printf("(%d) / 1080 * (%d) + (%d)\n", y, complex_plan->imag, complex_plan->imag_min);
			printf("(%f, %fi)\n", idx_real, idx_imag);
			// my_mlx_pixel_put(img, idx_real, idx_imag, 0x00FFFF);	
		}
	}
	// mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	// mlx_loop(img->mlx);

}