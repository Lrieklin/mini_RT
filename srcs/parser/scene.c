/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:09:24 by lrieklin          #+#    #+#             */
/*   Updated: 2022/11/02 21:09:26 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_scene	ft_new_scene(void)
{
	t_scene	new;

	new = (t_scene){};
	new.width = WIDTH;
	new.height = HEIGHT;
	return (new);
}
