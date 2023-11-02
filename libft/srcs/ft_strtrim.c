/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:42:36 by karisti-          #+#    #+#             */
/*   Updated: 2019/11/15 11:51:28 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ini;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	ini = 0;
	while (s1[ini] && ft_strchr(set, s1[ini]))
		ini++;
	end = ft_strlen(&s1[ini]);
	if (end != 0)
		while (s1[ini + end - 1] && ft_strchr(set, s1[ini + end - 1]))
			end--;
	return (ft_substr(s1, ini, end));
}
