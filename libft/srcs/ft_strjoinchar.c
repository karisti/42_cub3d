/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:20:13 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/10 18:41:07 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchar(char *s1, char c)
{
	char	*s2;
	char	*result;

	s2 = ft_strfromchar(c);
	if (!s2)
		return (NULL);
	result = ft_strjoin(s1, s2);
	free(s2);
	return (result);
}
