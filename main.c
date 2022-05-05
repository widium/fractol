/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:26:05 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/05 17:38:26 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int str_comp(char *first, char *second)
{
	int i;
	int size_f;
	int size_s;

	size_f = ft_strlen(first);
	size_s = ft_strlen(second);

	if (size_s != size_f)
		return (0);
	i = 0;
	while(first[i] && second[i])
	{
		if (first[i] != second[i])
			return (0);
		++i;
	}
	return (1);
}

int check_argc(int argc)
{
	if (argc > 3)
		return (0);
	else if (argc == 3 || argc == 2)
		return (1);
	else
		return (-1);
}

int is_digit(char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
		{
			if (!((str[i] >= '0' && str[i] <= '9')
			|| (str[i] == '-')))
				return (0);
			i++;
		}
	return (1);
}

int	check_name_fractal(char *argv)
{
	char *julia;
	char *mandelbrot;

	julia = "julia";
	mandelbrot = "mandelbrot";

	if (str_comp(argv, julia))
		return (1);
	if (str_comp(argv, mandelbrot))
		return (2);
	return (0);
}

int get_iterations(char *argv)
{
	int nbr;

	if (is_digit(argv))
	{
		nbr = ft_atoi(argv);
		return (nbr);
	}
	return (-1);
}

t_model *init_model()
{
	t_model *model;

	model = (t_model *)malloc(sizeof(t_model));
	if (!model)
		return (NULL);
	model->model = 0;
	model->iterations = 0;
	model->false_iterations = 0;
	model->empty = 0;
	model->to_much = 0;
	return (model);
}

t_model *check_input(int argc, char **argv)
{
	int i;
	t_model *model;


	model = init_model();
	i = 1;
	if (argc > 3)
	{
		model->to_much = 1;
		return (model);
	}
	else if (argc == 1)
	{
		model->empty = 1;
		return (model);
	}
	else
	{
		if (argc == 2)
		{
			model->model = check_name_fractal(argv[i]);
			model->iterations = 100;
		}
				
		else if (argc == 3)
		{
			model->model = check_name_fractal(argv[i]);
			model->iterations = get_iterations(argv[i+1]);
			if (model->iterations == -1)
				model->false_iterations = 1;
		}	
	}
	return (model);
}



// int choose_figure(int argc, char **argv)
// {
// 	char *julia;
// 	char *mandelbrot;

// 	julia = "julia";
// 	mandelbrot = "mandelbrot"

	
// }

int main(int argc, char **argv)
{
	t_model *model;
	// printf("%d\n",argc);
	// printf("%s\n", argv[1]);
	// printf("%d\n", str_comp(argv[1], "mandelbrot"));
	// printf("%d\n",check_input(argc, argv));
	model = check_input(argc, argv);
	printf("model -> %d\n", model->model);
	printf("iterations -> %d\n", model->iterations);
	printf("false_iterations -> %d\n", model->false_iterations);
	printf("Input vide ? -> %d\n", model->empty);
	printf("To many args ? %d\n", model->to_much);
}
