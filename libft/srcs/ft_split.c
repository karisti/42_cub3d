/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:58:54 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/10 18:30:49 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char *s, char c)
{
	size_t	nb_words;

	while (*s && *s == c)
		++s;
	if (*s)
		nb_words = 1;
	else
		nb_words = 0;
	while (*s)
	{
		if (*s == c && s[1] && s[1] != c)
			++nb_words;
		++s;
	}
	return (nb_words);
}

char	**ft_split(char const *s, char c)
{
	size_t	nb_words;
	char	*wrd;
	char	**result;

	nb_words = count_words((char *)s, c);
	result = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!result)
		return (NULL);
	wrd = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (wrd != s)
				*(result++) = ft_substr(wrd, 0, s - wrd);
			wrd = (char *)s + 1;
		}
		++s;
	}
	if (wrd != s)
		*(result++) = ft_substr(wrd, 0, s - wrd);
	*result = NULL;
	return (result - nb_words);
}
