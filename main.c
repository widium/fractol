/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:26:05 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/04 17:53:12 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <mlx.h>
# include <stdio.h>

# include <mlx.h>
# include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int x;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.bits_per_pixel = 4 * 8;
	img.line_length /= 4;
	img.endian = 0;
	img.addr = mlx_get_data_addr(img.img, 
								&img.bits_per_pixel, 
								&img.line_length,
								&img.endian);
	for (int y = 0; y < 1000; y++)
		for (int x = 0; x < 1920; x++)
			my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}