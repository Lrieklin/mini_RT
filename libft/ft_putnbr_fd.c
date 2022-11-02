/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 22:43:27 by lrieklin          #+#    #+#             */
/*   Updated: 2022/01/19 15:58:51 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_num_check(int nb, int fd)
{
	char	sub_sym;

	if (nb == 0)
	{
		sub_sym = '0';
		write(fd, &sub_sym, 1);
	}
	else
	{
		if (nb < 0)
		{
			sub_sym = '-';
			write(fd, &sub_sym, 1);
		}
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	char		sub_sym;
	int			size;
	int			nums[10];
	long int	nb_2;

	nb_2 = (long int)nb;
	ft_num_check(nb, fd);
	size = -1;
	if (nb_2 < 0)
		nb_2 = nb_2 * (-1);
	while (nb_2)
	{
		size++;
		nums[size] = nb_2 % 10;
		nb_2 = nb_2 / 10;
	}
	while (size >= 0)
	{
		sub_sym = nums[size] + '0';
		write(fd, &sub_sym, 1);
		size--;
	}
}
