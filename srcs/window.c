/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:56:55 by karisti-          #+#    #+#             */
/*   Updated: 2021/11/26 01:59:12 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_image(t_params *params)
{
	t_ray	rays[RAY_AMOUNT];

	draw_3d(params, rays);
	draw2d_minimap(params, rays);
}

int	refresh_image(t_params *params)
{
	controls_move(params);
	controls_rotate(params);
	draw_image(params);
	mlx_put_image_to_window(params->mlx, params->win, params->img, 0, 0);
	mlx_destroy_image(params->mlx, params->img);
	params->img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->img_adr = mlx_get_data_addr(params->img, &(params->bits_per_pixel),
			&(params->size_line), &(params->endian));
	return (0);
}

int	build_mlx(t_params *params)
{
	params->mlx = mlx_init();
	init_map(params);
	init_player(params);
	init_controls(params);
	params->win = mlx_new_window(params->mlx, WIDTH, HEIGHT, "cub3D");
	params->img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->img_adr = mlx_get_data_addr(params->img, &(params->bits_per_pixel),
			&(params->size_line), &(params->endian));
	refresh_image(params);
	mlx_hook(params->win, 17, 1L << 17, exit_clean, params);
	mlx_hook(params->win, 2, 1L << 0, key_press, params);
	mlx_hook(params->win, 3, 1L << 1, key_release, params);
	mlx_loop_hook(params->mlx, refresh_image, params);
	mlx_loop(params->mlx);
	return (0);
}
