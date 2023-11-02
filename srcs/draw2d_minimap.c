/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2d_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:47:37 by karisti-          #+#    #+#             */
/*   Updated: 2021/11/25 23:59:16 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_rays(t_params *params, t_ray *rays)
{
	int			m_player_x;
	int			m_player_y;
	t_point		a;
	t_point		b;
	int			i;

	m_player_x = params->player.x * params->map.minprop / params->map.prop;
	m_player_y = params->player.y * params->map.minprop / params->map.prop;
	i = 0;
	while (++i < RAY_AMOUNT)
	{
		a.x = m_player_x;
		a.y = m_player_y;
		b.x = rays[i].rx * params->map.minprop / params->map.prop;
		b.y = rays[i].ry * params->map.minprop / params->map.prop;
		draw_line(params, a, b, 0x4000FF);
	}
}

void	draw_player(t_params *params)
{
	int	x;
	int	y;
	int	m_player_x;
	int	m_player_y;

	m_player_x = params->player.x * params->map.minprop / params->map.prop;
	m_player_y = params->player.y * params->map.minprop / params->map.prop;
	x = m_player_x - 3;
	while (x++ < m_player_x + 3)
	{
		y = m_player_y - 3;
		while (y++ < m_player_y + 3)
		{
			if (x + 3 < WIDTH && x - 3 > 0 && y + 3 < HEIGHT && y - 3 > 0)
				put_pixel(params, x, y, 0x1600FF);
		}
	}
}

void	draw_square(t_params *params, int x, int y, int colour)
{
	int	xo;
	int	yo;

	yo = y * params->map.minprop;
	while (yo++ < y * params->map.minprop + params->map.minprop)
	{
		xo = x * params->map.minprop;
		while (xo++ < x * params->map.minprop + params->map.minprop)
		{
			put_pixel(params, xo, yo, colour);
		}
	}
}

void	draw_grid(t_params *params)
{
	int	x;
	int	y;
	int	colour;

	y = -1;
	while (++y < params->map.height)
	{
		x = -1;
		while (++x < params->map.width)
		{
			colour = 0x000000;
			if (params->map.grid[y][x] == '1')
				colour = 0xFFFFFF;
			draw_square(params, x, y, colour);
		}
	}
}

void	draw2d_minimap(t_params *params, t_ray *rays)
{
	draw_grid(params);
	draw_player(params);
	draw_rays(params, rays);
}
