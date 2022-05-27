/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:26:16 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/27 17:10:19 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	str_comp(char *first, char *second)
{
	int	i;
	int	size_f;
	int	size_s;

	size_f = ft_strlen(first);
	size_s = ft_strlen(second);
	if (size_s != size_f)
		return (0);
	i = 0;
	while (first[i] && second[i])
	{
		if (first[i] != second[i])
			return (0);
		++i;
	}
	return (1);
}

int	check_argc(int argc)
{
	if (argc > 3)
		return (0);
	else if (argc == 3 || argc == 2)
		return (1);
	else
		return (-1);
}

int	is_digit(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] == '-')))
			return (0);
		i++;
	}
	return (1);
}

int	check_name_fractal(char *argv)
{
	char	*julia;
	char	*mandelbrot;

	julia = "julia";
	mandelbrot = "mandelbrot";
	if (str_comp(argv, julia))
		return (1);
	if (str_comp(argv, mandelbrot))
		return (2);
	return (0);
}
