/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:52:43 by karisti-          #+#    #+#             */
/*   Updated: 2021/11/25 19:46:57 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	fix_ray_angle(double ra)
{
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	return (ra);
}

int	roundUp(int numToRound, int multiple)
{
	int	remainder;

	remainder = numToRound % multiple;
	if (multiple == 0 || remainder == 0)
		return (numToRound);
	return (numToRound + multiple - remainder);
}

int	roundDown(int numToRound, int multiple)
{
	int	remainder;

	remainder = numToRound % multiple;
	if (multiple == 0 || remainder == 0)
		return (numToRound);
	return (numToRound - remainder);
}

float	dist(double ax, double ay, double bx, double by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

int	get_tex_colour(t_tex *tex, int x, int y)
{
	if (x >= 0 && x < tex->width
		&& y >= 0 && y < tex->height)
	{
		return (tex->img_adr[tex->height * y + x]);
	}
	return (0x0);
}
