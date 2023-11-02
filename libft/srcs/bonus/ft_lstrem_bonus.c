/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:26:54 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/10 18:36:04 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstrem(t_list **alst, void *content)
{
	t_list	*lst;
	t_list	*lst_prev;

	if (!*alst)
		return ;
	lst = *alst;
	lst_prev = *alst;
	while (lst && lst->content != content)
	{
		lst_prev = lst;
		lst = lst->next;
	}
	if (lst->content == content)
	{
		if (lst == lst_prev)
			*alst = lst->next;
		else
			lst_prev->next = lst->next;
		lst->content = 0;
		free(lst);
	}
}
