/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:52:11 by karisti-          #+#    #+#             */
/*   Updated: 2019/11/20 17:26:18 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	unsigned char		*src1;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	if (src1 < dst1)
		while (++i <= len)
			dst1[len - i] = src1[len - i];
	else
		while (len-- > i)
			*(dst1++) = *(src1++);
	return (dst);
}
