/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:08:33 by karisti-          #+#    #+#             */
/*   Updated: 2021/11/26 10:23:32 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_params(t_params *params)
{
	params->rgb_ceil = NULL;
	params->rgb_floor = NULL;
	params->texture_no = NULL;
	params->texture_so = NULL;
	params->texture_we = NULL;
	params->texture_ea = NULL;
	params->map.height = 0;
	params->map.width = 0;
	params->escape_lines = 0;
	params->map.init_x = -1;
	params->map.init_y = -1;
	params->map.init_dir = '\0';
	params->map.grid = NULL;
	params->line = NULL;
}

void	init_map_memory(t_params *params)
{
	int	i;

	params->map.grid = (char **)xmalloc(params,
			sizeof(char *) * params->map.height + 1);
	i = -1;
	while (++i < params->map.height)
	{
		params->map.grid[i] = (char *)xmalloc(params,
				sizeof(char) * (params->map.width + 1));
		ft_memset(params->map.grid[i], ' ', params->map.width);
	}
}

void	init_player(t_params *params)
{
	if (params->map.init_dir == 'N')
		params->player.a = PI / 2;
	else if (params->map.init_dir == 'S')
		params->player.a = 3 * PI / 2;
	else if (params->map.init_dir == 'W')
		params->player.a = PI;
	else if (params->map.init_dir == 'E')
		params->player.a = 0;
	params->player.x = params->map.init_x * params->map.prop
		+ params->map.prop / 2;
	params->player.y = params->map.init_y * params->map.prop
		+ params->map.prop / 2;
	params->player.dx = cos(params->player.a) * 5;
	params->player.dy = sin(params->player.a) * 5;
}

void	init_controls(t_params *params)
{
	params->controls.right = 0;
	params->controls.left = 0;
	params->controls.w = 0;
	params->controls.s = 0;
	params->controls.a = 0;
	params->controls.d = 0;
}

void	init_map(t_params *params)
{
	int		width;
	int		height;

	params->map.texture_no = mlx_xpm_file_to_image(params->mlx,
			(char *)params->texture_no, &width, &height);
	params->map.texture_so = mlx_xpm_file_to_image(params->mlx,
			(char *)params->texture_so, &width, &height);
	params->map.texture_we = mlx_xpm_file_to_image(params->mlx,
			(char *)params->texture_we, &width, &height);
	params->map.texture_ea = mlx_xpm_file_to_image(params->mlx,
			(char *)params->texture_ea, &width, &height);
	if (!params->map.texture_no || !params->map.texture_so
		|| !params->map.texture_ea || !params->map.texture_we)
		exit_error("Invalid texture", params);
	params->ceil_colour = get_hex_colour((int *)params->rgb_ceil);
	params->floor_colour = get_hex_colour((int *)params->rgb_floor);
	params->map.prop = params->map.texture_no->width;
	if (params->map.height > params->map.width)
		params->map.minprop = HEIGHT / params->map.height * MINMAP_P / 100;
	else
		params->map.minprop = HEIGHT / params->map.width * MINMAP_P / 100;
}
