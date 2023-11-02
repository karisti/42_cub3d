/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:21:53 by karisti-          #+#    #+#             */
/*   Updated: 2021/11/25 23:54:26 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// looking DOWN (ra > PI) or UP (ra < PI)
void	check_side_horizontal(t_params *params, t_ray *ray, double ra)
{
	double	aTan;

	aTan = 1 / tan(ra);
	if (ra > PI)
	{
		ray->ry = roundUp(params->player.y, params->map.prop);
		ray->rx = (params->player.y - ray->ry) * aTan + params->player.x;
		ray->yo = params->map.prop;
		ray->xo = -ray->yo * aTan;
	}
	else if (ra < PI)
	{
		ray->ry = roundDown(params->player.y, params->map.prop) - 0.0001;
		ray->rx = (params->player.y - ray->ry) * aTan + params->player.x;
		ray->yo = -params->map.prop;
		ray->xo = -ray->yo * aTan;
	}
}

// Looking LEFT (ra > PI / 2 && ra < 3 * PI / 2)
// or RIGHT (ra < PI / 2 || ra > 3 * PI / 2)
void	check_side_vertical(t_params *params, t_ray *ray, double ra)
{
	double	nTan;

	nTan = tan(ra);
	if (ra > PI / 2 && ra < 3 * PI / 2)
	{
		ray->rx = roundDown(params->player.x, params->map.prop) - 0.0001;
		ray->ry = (params->player.x - ray->rx) * nTan + params->player.y;
		ray->xo = -params->map.prop;
		ray->yo = -ray->xo * nTan;
	}
	else if (ra < PI / 2 || ra > 3 * PI / 2)
	{
		ray->rx = roundUp(params->player.x, params->map.prop);
		ray->ry = (params->player.x - ray->rx) * nTan + params->player.y;
		ray->xo = params->map.prop;
		ray->yo = -ray->xo * nTan;
	}
}

void	calculate_ray_horizontal(t_params *params, t_ray *ray, double ra)
{
	int	dof;

	dof = 0;
	check_side_horizontal(params, ray, ra);
	while (dof < params->map.height)
	{
		ray->mx = ray->rx / params->map.prop;
		ray->my = ray->ry / params->map.prop;
		if (ray->mx < params->map.width && ray->my < params->map.height
			&& ray->mx >= 0 && ray->my >= 0
			&& params->map.grid[ray->my][ray->mx] == '1')
		{
			dof = params->map.height;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			dof += 1;
		}
	}
	ray->dist = dist(params->player.x, params->player.y, ray->rx, ray->ry);
}

void	calculate_ray_vertical(t_params *params, t_ray *ray, double ra)
{
	int	dof;

	dof = 0;
	check_side_vertical(params, ray, ra);
	while (dof < params->map.width)
	{
		ray->mx = ray->rx / params->map.prop;
		ray->my = ray->ry / params->map.prop;
		if (ray->mx < params->map.width && ray->my < params->map.height
			&& ray->mx >= 0 && ray->my >= 0
			&& params->map.grid[ray->my][ray->mx] == '1')
		{
			dof = params->map.width;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			dof += 1;
		}
	}
	ray->dist = dist(params->player.x, params->player.y, ray->rx, ray->ry);
}
