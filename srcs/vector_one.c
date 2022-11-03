/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:07:34 by lrieklin          #+#    #+#             */
/*   Updated: 2022/11/03 00:56:36 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec3	ft_new_vec3(float x, float y, float z)
{
	t_vec3	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_vec3	ft_add(t_vec3 *a, t_vec3 *b)
{
	t_vec3	res;

	res.x = a->x + b->x;
	res.y = a->y + b->y;
	res.z = a->z + b->z;
	return (res);
}

t_vec3	ft_add3(t_vec3 *a, t_vec3 *b, t_vec3 *c)
{
	t_vec3	res;

	res.x = a->x + b->x + c->x;
	res.y = a->y + b->y + c->y;
	res.z = a->z + b->z + c->z;
	return (res);
}

t_vec3	ft_sub(t_vec3 *a, t_vec3 *b)
{
	t_vec3	res;

	res.x = a->x - b->x;
	res.y = a->y - b->y;
	res.z = a->z - b->z;
	return (res);
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
