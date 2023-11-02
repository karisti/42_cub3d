/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:26:21 by karisti-          #+#    #+#             */
/*   Updated: 2021/11/25 23:59:16 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fix_distances(t_params *params, t_ray *ray_h, t_ray *ray_v, float ra)
{
	if (ray_h->rx < params->player.x && (ra > 2 * PI - 0.1 || ra < 0 + 0.1))
		ray_h->dist = 10000000;
	if (ray_v->ry > params->player.y
		&& (ra > PI / 2 - 0.1 && ra < PI / 2 + 0.1))
		ray_v->dist = 10000000;
	if (ray_h->rx > params->player.x && (ra > PI - 0.1 && ra < PI + 0.1))
		ray_h->dist = 10000000;
	if (ray_v->ry < params->player.y
		&& (ra > (3 * PI / 2) - 0.1 && ra < (3 * PI / 2) + 0.1))
		ray_v->dist = 10000000;
}

void	get_texture(t_params *params, t_draw *draw)
{
	draw->texture = NULL;
	draw->vertical = 0;
	if (draw->ray_v.dist < draw->ray_h.dist)
	{
		draw->ray_t = draw->ray_v;
		if (draw->ra < PI / 2 || draw->ra > 3 * PI / 2)
			draw->texture = params->map.texture_ea;
		else
			draw->texture = params->map.texture_we;
		draw->vertical = 1;
	}
	else if (draw->ray_h.dist <= draw->ray_v.dist)
	{
		draw->ray_t = draw->ray_h;
		if (draw->ra > PI)
			draw->texture = params->map.texture_so;
		else
			draw->texture = params->map.texture_no;
	}
}

void	calculate_img_values(t_params *params, t_draw *draw)
{
	draw->ca = params->player.a - draw->ra;
	draw->ca = fix_ray_angle(draw->ca);
	draw->ray_t.dist = draw->ray_t.dist * cos(draw->ca);
	draw->lineH = (100 * HEIGHT) / draw->ray_t.dist;
	draw->ty_step = draw->texture->height / (float) draw->lineH;
	draw->ty_off = 0;
	if (draw->lineH > HEIGHT)
	{
		draw->ty_off = (draw->lineH - HEIGHT) / 2.0;
		draw->lineH = HEIGHT;
	}
	draw->lineO = HEIGHT / 2 - draw->lineH / 2;
	draw->ty = draw->ty_off * draw->ty_step;
	if (draw->vertical)
		draw->tx = (int)(draw->ray_t.ry) % draw->texture->width;
	else
		draw->tx = (int)(draw->ray_t.rx) % draw->texture->width;
}

void	draw_image_values(t_params *params, t_draw *draw, int i)
{
	int		j;
	int		c;

	j = -1;
	while (++j <= draw->lineO)
		put_pixel(params, (RAY_AMOUNT - 1 - i), j, params->ceil_colour);
	j--;
	while (++j < draw->lineH + draw->lineO)
	{
		c = get_tex_colour(draw->texture, draw->tx, draw->ty);
		put_pixel(params, (RAY_AMOUNT - 1 - i), j,
			createRGB(c >> 16, c >> 8, c));
		draw->ty += draw->ty_step;
	}
	j--;
	while (++j < draw->lineH + draw->lineO * 2)
		put_pixel(params, (RAY_AMOUNT - 1 - i), j, params->floor_colour);
}

void	draw_3d(t_params *params, t_ray *rays)
{
	t_draw	draw;
	int		i;

	draw.ra = params->player.a - (DR * 60 / WIDTH) * (WIDTH / 2);
	draw.ra = fix_ray_angle(draw.ra);
	i = -1;
	while (++i < RAY_AMOUNT)
	{
		calculate_ray_horizontal(params, &draw.ray_h, draw.ra);
		calculate_ray_vertical(params, &draw.ray_v, draw.ra);
		fix_distances(params, &draw.ray_h, &draw.ray_v, draw.ra);
		get_texture(params, &draw);
		rays[i] = draw.ray_t;
		calculate_img_values(params, &draw);
		draw_image_values(params, &draw, i);
		draw.ra += (DR * 60 / WIDTH);
		draw.ra = fix_ray_angle(draw.ra);
	}
}
