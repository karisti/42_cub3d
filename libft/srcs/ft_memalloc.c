/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:34:24 by karisti-          #+#    #+#             */
/*   Updated: 2020/01/12 13:36:25 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (size)
	{
		ptr = malloc(size);
		if (ptr)
		{
			ft_bzero(ptr, size);
			return (ptr);
		}
	}
	return (0);
}
