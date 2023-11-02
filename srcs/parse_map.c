/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:09:31 by karisti-          #+#    #+#             */
/*   Updated: 2021/11/26 10:31:29 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_map_closed(t_params *params, int i, int j)
{
	int	x;
	int	y;

	i = -1;
	while (++i < params->map.height)
	{
		j = -1;
		while (++j < params->map.width)
		{
			if (!ft_strchr("0NSEW", params->map.grid[i][j]))
				continue ;
			if (j == 0 || j == params->map.width - 1
				|| i == 0 || i == params->map.height - 1)
				exit_error("Invalid map, map is not closed", params);
			x = i - 2;
			while (++x < i + 2)
			{
				y = j - 2;
				while (++y < j + 2)
					if (params->map.grid[x][y] == ' ')
						exit_error("Invalid map, is not closed", params);
			}
		}
	}
}

void	get_row_values(int i, char *line, t_params *params)
{
	int		j;
	int		line_size;

	j = 0;
	line_size = ft_strlen(line);
	while (j < line_size)
	{
		params->map.grid[i][j] = line[j];
		if (ft_strchr("NSEW", line[j]))
		{
			if (params->map.init_dir != '\0')
				exit_error("Invalid map, multiple initial positions", params);
			params->map.init_x = j;
			params->map.init_y = i;
			params->map.init_dir = line[j];
		}
		j++;
	}
}

void	parse_map(int fd, t_params *params)
{
	int	i;

	i = 0;
	init_map_memory(params);
	while (ft_get_next_line(fd, &params->line) != 0 || params->line[0] != '\0')
	{
		if (params->line[0] != '\0')
			get_row_values(i++, params->line, params);
		else if (i > 0 && i < params->map.height)
			exit_error("Invalid map, empty line detected", params);
		free_line(params);
	}
	free_line(params);
}

void	get_map_size(int fd, t_params *params)
{
	int		i;

	while (ft_get_next_line(fd, &params->line) != 0 || params->line[0] != '\0')
	{
		i = -1;
		while (params->line[++i])
			if (!ft_strchr("01 NSEW", params->line[i]))
				exit_error("Invalid map, not valid char", params);
		if (i > 0)
			params->map.height++;
		if (i > params->map.width)
			params->map.width = i;
		free_line(params);
	}
	free_line(params);
}
