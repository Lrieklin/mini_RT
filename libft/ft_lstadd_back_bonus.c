/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:05:17 by lrieklin          #+#    #+#             */
/*   Updated: 2022/04/16 23:03:38 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*p;

	p = *lst;
	if (p == NULL)
		*lst = new;
	else
	{
		while ((p)->next != NULL)
			p = p->next;
		p->next = new;
		new->next = NULL;
	}
}
