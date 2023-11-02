/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:34:24 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/10 18:39:13 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_char(long long n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_ltoa(long long n)
{
	char	*s;
	int		i;
	int		len;

	if ((long long)n < -9223372036854775807)
		return ("-9223372036854775808");
	i = 0;
	len = ft_count_char(n);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (n > 9)
	{
		s[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	s[len - 1] = n + '0';
	return (s);
}
