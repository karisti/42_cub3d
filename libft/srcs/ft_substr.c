/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:49:07 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/10 18:42:08 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;

	if (!s)
		return (NULL);
	s1 = malloc(sizeof(char) * (len + 1));
	if (s1)
	{
		i = 0;
		if (ft_strlen(s) > start)
		{
			while (i < len)
			{
				s1[i] = s[start + i];
				i++;
			}
		}
		s1[i] = '\0';
		return (s1);
	}
	return (NULL);
}
