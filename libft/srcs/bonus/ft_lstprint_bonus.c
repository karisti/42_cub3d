/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:24:10 by karisti-          #+#    #+#             */
/*   Updated: 2023/11/02 19:24:53 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_nbr(t_list *lst)
{
	t_list	*list;

	list = lst;
	while (list)
	{
		ft_putnbr_fd(*((int *)list->content), 1);
		ft_putstr_fd(" -> ", 1);
		list = list->next;
	}
	ft_putstr_fd("null\n", 1);
}
