/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:07:27 by lrieklin          #+#    #+#             */
/*   Updated: 2022/11/02 23:06:01 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

float	ft_dist(t_vec3 a, t_vec3 b)
{
	float	distance;
	t_vec3	subtraction;

	subtraction = ft_sub(&b, &a);
	distance = ft_length(subtraction);
	return (distance);
}

t_vec3	ft_reflect(t_vec3 *rd, t_vec3 *n)
{
	t_vec3	reflect;
	t_vec3	tmp;

	tmp = ft_s_mul(n, (2 * ft_dot(n, rd)));
	reflect = ft_sub(rd, &tmp);
	reflect = ft_norm(&reflect);
	return (reflect);
}
