/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:09:14 by karisti-          #+#    #+#             */
/*   Updated: 2019/11/20 18:20:54 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;

	len = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, len + 1);
	return (p);
}
