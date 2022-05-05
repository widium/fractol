/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:11:17 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/05 18:27:04 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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



// t_model *init_model()
// {
// 	t_model *model;

// 	model = (t_model *)malloc(sizeof(t_model));
// 	if (!model)
// 		return (NULL);
// 	model->model = 0;
// 	model->iterations = 0;
// 	model->false_iterations = 0;
// 	model->empty = 0;
// 	model->to_much = 0;
// 	return (model);
// }

