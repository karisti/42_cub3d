/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:40:16 by karisti-          #+#    #+#             */
/*   Updated: 2021/11/26 10:33:47 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned long	get_hex_colour(int *colour)
{
	return (createRGB(colour[0], colour[1], colour[2]));
}

unsigned long	createRGB(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	free_line(t_params *params)
{
	void	*aux;

	if (params->line != NULL)
	{
		aux = params->line;
		params->line = NULL;
		free(aux);
	}
}

void	*xmalloc(t_params *params, size_t size)
{
	void	*ptr;

	ptr = ft_memalloc(size);
	if (!ptr)
		exit_error("Malloc error", params);
	return (ptr);
}
