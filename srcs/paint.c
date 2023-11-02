/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:30:01 by karisti-          #+#    #+#             */
/*   Updated: 2021/11/26 00:12:03 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pixel(t_params *params, int x, int y, int color)
{
	char	*dst;

	dst = params->img_adr + (y * params->size_line + x
			* (params->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line1(t_bresenham	*bh, t_point a, t_point b)
{
	bh->dx = abs(b.x - a.x);
	bh->dy = abs(b.y - a.y);
	bh->sx = -1;
	if (a.x < b.x)
		bh->sx = 1;
	bh->sy = -1;
	if (a.y < b.y)
		bh->sy = 1;
	bh->err = -bh->dy / 2;
	if (bh->dx > bh->dy)
		bh->err = bh->dx / 2;
}

void	draw_line(t_params *params, t_point a, t_point b, int colour)
{
	t_bresenham	bh;

	draw_line1(&bh, a, b);
	while (a.x != b.x || a.y != b.y)
	{
		if (a.y > 0 && a.x > 0 && a.y < HEIGHT && a.x < WIDTH)
			put_pixel(params, a.x, a.y, colour);
		bh.e2 = bh.err;
		if (bh.e2 > -bh.dx)
		{
			bh.err -= bh.dy;
			a.x += bh.sx;
		}
		if (bh.e2 < bh.dy)
		{
			bh.err += bh.dx;
			a.y += bh.sy;
		}
	}
}
