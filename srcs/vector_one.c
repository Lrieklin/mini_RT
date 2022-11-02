/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:07:34 by lrieklin          #+#    #+#             */
/*   Updated: 2022/11/02 23:06:10 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec3	ft_new_vec3(float x, float y, float z)
{
	t_vec3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vec3	ft_add(t_vec3 *a, t_vec3 *b)
{
	t_vec3	addition;

	addition.x = a->x + b->x;
	addition.y = a->y + b->y;
	addition.z = a->z + b->z;
	return (addition);
}

t_vec3	ft_add3(t_vec3 *a, t_vec3 *b, t_vec3 *c)
{
	t_vec3	addition3;

	addition3.x = a->x + b->x + c->x;
	addition3.y = a->y + b->y + c->y;
	addition3.z = a->z + b->z + c->z;
	return (addition3);
}

t_vec3	ft_sub(t_vec3 *a, t_vec3 *b)
{
	t_vec3	subtraction;

	subtraction.x = a->x - b->x;
	subtraction.y = a->y - b->y;
	subtraction.z = a->z - b->z;
	return (subtraction);
}

t_vec3	ft_norm(t_vec3 *a)
{
	t_vec3	new;
	float	length;

	length = ft_length(*a);
	new.x = a->x / length;
	new.y = a->y / length;
	new.z = a->z / length;
	return (new);
}
