/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:00:50 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/10 18:39:53 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	unsigned int	tmp;
	int				chars;

	chars = 0;
	tmp = n;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		tmp = tmp * -1;
		chars++;
	}
	while (tmp > 0)
	{
		tmp = tmp / 10;
		chars++;
	}
	return (chars);
}

static void	ft_nbrstr(int n, char *str, int *pos)
{
	unsigned int	nb_1;

	if (n < 0)
	{
		str[*pos] = '-';
		*pos = *pos + 1;
		n = n * -1;
	}
	nb_1 = n;
	if (nb_1 >= 10)
	{
		ft_nbrstr(nb_1 / 10, str, pos);
	}
	nb_1 = nb_1 % 10 + '0';
	str[*pos] = nb_1;
	*pos = *pos + 1;
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*result;
	int		*ppos;
	int		pos;

	digits = count_digits(n);
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (NULL);
	pos = 0;
	ppos = &pos;
	ft_nbrstr(n, result, ppos);
	result[*ppos] = '\0';
	return (result);
}
