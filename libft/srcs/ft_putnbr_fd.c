/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:17:59 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/10 18:44:03 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb_1;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	nb_1 = n;
	if (nb_1 >= 10)
	{
		ft_putnbr_fd(nb_1 / 10, fd);
	}
	nb_1 = nb_1 % 10 + '0';
	write(fd, &nb_1, 1);
}
