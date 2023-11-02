/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:20:13 by karisti-          #+#    #+#             */
/*   Updated: 2019/11/16 21:21:21 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_size;
	unsigned int	s2_size;
	unsigned int	i;
	unsigned int	j;
	char			*sj;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	sj = malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (sj)
	{
		i = -1;
		while (++i < s1_size)
			sj[i] = s1[i];
		j = 0;
		while (j < s2_size)
			sj[i++] = s2[j++];
		sj[i] = '\0';
		return (sj);
	}
	return (NULL);
}
