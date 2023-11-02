/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfromchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:09:14 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/10 18:40:35 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfromchar(char c)
{
	char	*p;

	p = ft_calloc(2, sizeof(char));
	if (!p)
		return (NULL);
	p[0] = c;
	return (p);
}
