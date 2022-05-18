/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:24:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/18 20:25:52 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_iterations(char *argv)
{
	int	nbr;

	if (is_digit(argv))
	{
		nbr = ft_atoi(argv);
		return (nbr);
	}
	return (-1);
}

t_env	*check_input(int argc, char **argv, t_env *env)
{
	int	i;

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
		env->model->iter_max = get_iterations(argv[i + 1]);
		if (env->model->iter_max == -1)
			env->input->false_iterations = 1;
	}	
	return (env);
}

void	print_status(t_env *env)
{
	ft_putstr_fd("============ Error ===============\n", 1);
	ft_putstr_fd(
		"Passer le nom de la fractales souhaiter en premier parametres\n", 1);
	ft_putstr_fd("-----| julia, mandelbrot |-----\n", 1);
	ft_putstr_fd(
		"Indiquer le Nombre d'iterations en 2e argument (default [100])\n", 1);
	ft_putstr_fd("Ex : julia 1000\n", 1);
	ft_putstr_fd("===============================\n", 1);
}

int	define_status(t_env *env)
{
	if (env->input->empty)
		return (0);
	if (env->input->false_iterations)
		return (0);
	if (env->input->to_much)
		return (0);
	if (env->model->name == 0)
		return (0);
	return (1);
}
