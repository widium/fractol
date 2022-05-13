/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:05:16 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/13 15:59:23 by ebennace         ###   ########.fr       */
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

t_env *check_input(int argc, char **argv, t_env *env)
{
	int i;

	i = 1;
	if (argc > 3)
		env->input->to_much = 1;
	else if (argc == 1)
	{
		env->input->empty = 1;
		return (env);
	}
	if (argc == 2)
	{
		env->model->name = check_name_fractal(argv[i]);
		env->model->iter_max = 100;
	}	
	else if (argc > 2)
	{
		env->model->name = check_name_fractal(argv[i]);
		env->model->iter_max = get_iterations(argv[i+1]);
		if (env->model->iter_max == -1)
			env->input->false_iterations = 1;
	}	
	return (env);
}


int print_status(t_env *env)
{
	printf("empty -> (%d)\n", env->input->empty);
	printf("false iterations ? -> (%d)\n", env->input->false_iterations);
	printf("trop d'arguments -> (%d)\n", env->input->to_much);
	printf("le model est -> (%d)\n", env->model->name);
	printf("iter_max -> (%d)\n", env->model->iter_max);
	return (1);
	
}