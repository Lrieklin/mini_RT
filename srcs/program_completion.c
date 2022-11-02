/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_completion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:07:44 by lrieklin          #+#    #+#             */
/*   Updated: 2022/11/02 21:07:46 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_exit(t_main *data, char *str, int flag)
{
	if (data->scene.sh != NULL)
	{
		while (data->scene.sh)
		{
			free(data->scene.sh);
			data->scene.sh = data->scene.sh->next;
		}
	}
	if (flag > 1)
		perror(str);
	else
		ft_putstr_fd(str, 2);
	if (flag > 0)
		flag = 1;
	exit (flag);
}
