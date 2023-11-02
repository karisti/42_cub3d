/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:30:39 by karisti-          #+#    #+#             */
/*   Updated: 2021/11/19 22:13:00 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_params *params)
{
	if (keycode == KEY_ESC)
		exit_clean(params);
	if (keycode == KEY_RESET)
		init_player(params);
	if (keycode == KEY_RIGHT)
		params->controls.right = 1;
	if (keycode == KEY_LEFT)
		params->controls.left = 1;
	if (keycode == KEY_W)
		params->controls.w = 1;
	if (keycode == KEY_S)
		params->controls.s = 1;
	if (keycode == KEY_A)
		params->controls.a = 1;
	if (keycode == KEY_D)
		params->controls.d = 1;
	return (0);
}

int	key_release(int keycode, t_params *params)
{
	if (keycode == KEY_RIGHT)
		params->controls.right = 0;
	if (keycode == KEY_LEFT)
		params->controls.left = 0;
	if (keycode == KEY_W)
		params->controls.w = 0;
	if (keycode == KEY_S)
		params->controls.s = 0;
	if (keycode == KEY_A)
		params->controls.a = 0;
	if (keycode == KEY_D)
		params->controls.d = 0;
	return (0);
}

void	controls_move(t_params *params)
{
	if (params->controls.w)
	{
		params->player.y -= params->player.dy * 3;
		params->player.x += params->player.dx * 3;
	}
	if (params->controls.s)
	{
		params->player.y += params->player.dy * 3;
		params->player.x -= params->player.dx * 3;
	}
	if (params->controls.a)
	{
		params->player.y -= params->player.dx * 3;
		params->player.x -= params->player.dy * 3;
	}
	if (params->controls.d)
	{
		params->player.y += params->player.dx * 3;
		params->player.x += params->player.dy * 3;
	}
}

void	controls_rotate(t_params *params)
{
	if (params->controls.right)
	{
		params->player.a -= 0.1;
		if (params->player.a < 0)
			params->player.a += 2 * PI;
		params->player.dx = cos(params->player.a) * 3;
		params->player.dy = sin(params->player.a) * 3;
	}
	if (params->controls.left)
	{
		params->player.a += 0.1;
		if (params->player.a > 2 * PI)
			params->player.a -= 2 * PI;
		params->player.dx = cos(params->player.a) * 3;
		params->player.dy = sin(params->player.a) * 3;
	}
}
